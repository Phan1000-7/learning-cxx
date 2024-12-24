#include "../exercise.h"

// READ: Trivial type <https://learn.microsoft.com/zh-cn/cpp/cpp/trivial-standard-layout-and-pod-types?view=msvc-170>

struct FibonacciCache {
    unsigned long long cache[16] = {0, 1};  // 初始化前两个斐波那契数列值
    int cached = 2;  // 初始缓存 2 个斐波那契数列值
};

static unsigned long long fibonacci(FibonacciCache &cache, int i) {
    if (i < cache.cached) {
        return cache.cache[i];
    }
    
    for (int j = cache.cached; j <= i; ++j) {
        cache.cache[j] = cache.cache[j - 1] + cache.cache[j - 2];
    }
    
    cache.cached = i + 1;  // 更新缓存计数
    
    return cache.cache[i];
}

int main() {
    FibonacciCache fib;  // 初始化缓存结构体
    // 斐波那契数列的第 10 项应该是 55
    std::cout << "fibonacci(10) = " << fibonacci(fib, 10) << std::endl;
    
    return 0;
}
