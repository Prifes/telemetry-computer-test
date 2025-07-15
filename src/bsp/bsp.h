#ifndef BSP_H
#define BSP_H
#include <cstdint>

namespace board {
void Initialize();
void ToggleLed();
void Delay(uint32_t ms);
}  // namespace board

#endif  // BSP_H