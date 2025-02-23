#include "rtweekend.h"
#include "camera.h"
#include "hittable.h"
#include "hittable_list.h"
#include "material.h"
#include "sphere.h"

// Test Scene 1: Simple Scene
void render_simple_scene() {
    hittable_list world;

    // Ground
    auto ground_material = make_shared<lambertian>(color(0.5, 0.8, 0.5));
    world.add(make_shared<sphere>(point3(0,-1000,0), 1000, ground_material));

    // Center sphere - Glass
    auto center_material = make_shared<dielectric>(1.5);
    world.add(make_shared<sphere>(point3(0,1,0), 1.0, center_material));

    // Left sphere - Matte red
    auto left_material = make_shared<lambertian>(color(0.8, 0.2, 0.2));
    world.add(make_shared<sphere>(point3(-2,1,0), 1.0, left_material));

    // Right sphere - Metallic
    auto right_material = make_shared<metal>(color(0.8, 0.8, 0.8), 0.1);
    world.add(make_shared<sphere>(point3(2,1,0), 1.0, right_material));

    camera cam;
    cam.aspect_ratio = 16.0 / 9.0;
    cam.image_width = 800;
    cam.samples_per_pixel = 50;
    cam.max_depth = 20;
    cam.vfov = 30;
    cam.lookfrom = point3(0,2,8);
    cam.lookat = point3(0,1,0);
    cam.vup = vec3(0,1,0);
    cam.defocus_angle = 0.6;
    cam.focus_dist = 10.0;

    cam.render(world);
}

// Test Scene 2: Sunset Scene
void render_sunset_scene() {
    hittable_list world;

    // Orange-tinted ground
    auto ground_material = make_shared<lambertian>(color(0.8, 0.6, 0.3));
    world.add(make_shared<sphere>(point3(0,-1000,0), 1000, ground_material));

    // Add a row of spheres on the horizon
    for(int i = -3; i <= 3; i++) {
        auto sphere_material = make_shared<metal>(color(0.8, 0.6, 0.4), 0.1);
        world.add(make_shared<sphere>(point3(i*2, 1, -5), 1.0, sphere_material));
    }

    // Large "sun" sphere
    auto sun_material = make_shared<lambertian>(color(0.98, 0.7, 0.0));
    world.add(make_shared<sphere>(point3(0, 8, -30), 8.0, sun_material));

    camera cam;
    cam.aspect_ratio = 16.0 / 9.0;
    cam.image_width = 1200;
    cam.samples_per_pixel = 100;
    cam.max_depth = 50;
    cam.vfov = 45;
    cam.lookfrom = point3(0,2,15);
    cam.lookat = point3(0,1,-5);
    cam.vup = vec3(0,1,0);
    cam.defocus_angle = 0.3;
    cam.focus_dist = 15.0;

    cam.render(world);
}

// Test Scene 3: Glass Marbles
void render_marbles_scene() {
    hittable_list world;

    // Dark ground
    auto ground_material = make_shared<lambertian>(color(0.2, 0.2, 0.2));
    world.add(make_shared<sphere>(point3(0,-1000,0), 1000, ground_material));

    // Create a 3x3 grid of glass spheres
    for(int i = -1; i <= 1; i++) {
        for(int j = -1; j <= 1; j++) {
            auto glass = make_shared<dielectric>(1.5);
            world.add(make_shared<sphere>(
                point3(i*2, 1, j*2), 
                0.8, 
                glass));
            
            auto inner_material = make_shared<lambertian>(
                color(random_double(), random_double(), random_double()));
            world.add(make_shared<sphere>(
                point3(i*2, 1, j*2), 
                -0.7, 
                glass));
        }
    }

    camera cam;
    cam.aspect_ratio = 16.0 / 9.0;
    cam.image_width = 1200;
    cam.samples_per_pixel = 200; 
    cam.max_depth = 50;
    cam.vfov = 35;
    cam.lookfrom = point3(6,4,6);
    cam.lookat = point3(0,0,0);
    cam.vup = vec3(0,1,0);
    cam.defocus_angle = 0.4;
    cam.focus_dist = 8.0;

    cam.render(world);
}

int main() {
    std::cout << "Select scene to render (1-3):\n"
              << "1. Simple Three-Sphere Scene\n"
              << "2. Sunset Scene\n"
              << "3. Glass Marbles Scene\n";
    
    int choice;
    std::cin >> choice;
    
    switch(choice) {
        case 1:
            render_simple_scene();
            break;
        case 2:
            render_sunset_scene();
            break;
        case 3:
            render_marbles_scene();
            break;
        default:
            std::cout << "Invalid choice. Rendering simple scene.\n";
            render_simple_scene();
    }
    
    return 0;
}