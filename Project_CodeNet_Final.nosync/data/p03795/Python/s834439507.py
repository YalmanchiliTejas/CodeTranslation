import math
n = int(input())
ans = n * 800
ans -= 200 * math.floor(n / 15)
print(ans)