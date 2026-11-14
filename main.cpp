#include <cstdio>

int marker_value();

int main() {
  const int v = marker_value();
  std::printf("MARKER=%d\n", v);
  return v;
}
