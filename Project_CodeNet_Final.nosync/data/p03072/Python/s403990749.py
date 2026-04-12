import numpy as np

n = int(input())
h = list(map(int, input().split())) # 整数
max = 0
ans = 0

for i in range(n):
    if max <= h[i]:
        ans += 1
        max = h[i]

print(ans)
    
