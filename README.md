# Summary
The program creates photorealistic 3D images by simulating how light interacts with objects in a scene. It uses:
Core Technologies and Features:

1. Modern C++ (using std::shared_ptr, classes, templates)
2. Object-Oriented Design with inheritance (particularly for materials and hittable objects)
3. 3D Vector Mathematics
4. PPM image format output
5. Monte Carlo sampling for anti-aliasing and material effects

# Key Components:

Camera system with adjustable parameters (FOV, depth of field, positioning)
Multiple material types:

- Lambertian (diffuse/matte surfaces)
- Metal (reflective surfaces with adjustable fuzziness)
- Dielectric (glass-like materials with refraction)

Basic geometry support:
- Spheres
- Lists of hittable objects

Advanced features:
- Gamma correction
- Depth of field blur
- Anti-aliasing through multiple samples per pixel
- Ray bouncing with maximum depth control
- Schlick approximation for realistic glass reflections

The output is rendered as a PPM image with configurable width, aspect ratio, and quality settings (samples per pixel, max ray depth, etc.).

# Images

# Citations
https://raytracing.github.io/books/RayTracingInOneWeekend.html#outputanimage
