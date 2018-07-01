#include <vector>
#include <cstdio>

int main() {
  auto vec = std::vector<long int>(10);
  vec[0] = 1;
  vec[1] = 1;
  vec[2] = 1;
  vec[3] = 1;
  
  long int *ptr = &vec[3];
  long int &ref = vec[3];

  auto vec_dummy = std::vector<long int>(10);

  std::printf("Before resize ptr addr: %016lx\n", (unsigned long int) ptr);
  std::printf("Before resize ref addr: %016lx\n", (unsigned long int)(&ref));
  std::puts("Resize");

  vec.resize(100);

  std::printf("After resize ptr addr: %016lx\n", (unsigned long int) ptr);
  std::printf("After resize ref addr: %016lx\n", (unsigned long int)(&ref));
  std::printf("After resize real addr: %016lx\n", (unsigned long int) &vec[3]);

  return 0;
}
