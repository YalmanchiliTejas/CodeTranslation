import math
N = int(input())
x = 800 * N
y = math.floor(N / 15)
y *= 200
ans = x - y
print(ans)
