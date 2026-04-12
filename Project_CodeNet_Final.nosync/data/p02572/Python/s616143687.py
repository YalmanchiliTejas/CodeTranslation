from sys import stdin
import numpy as np
input = stdin.readline
n = input().rstrip()
n = int(n)
a = list(map(int, input().split()))
a = np.array(a)
suma = np.cumsum(np.array(a))

ans = 0
for i in range(n-1):
    x = suma[n-1] - suma[i]
    x %= 1000000007
    ans += a[i] * x
    ans %= 1000000007

print(ans)
