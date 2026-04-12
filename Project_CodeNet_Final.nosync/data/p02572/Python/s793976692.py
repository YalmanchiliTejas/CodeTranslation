n = int(input())
a = list(map(int, input().split()))
k = 0
num = sum(a)
import math

for i in range(n):
    reje = num - a[i]
    k += reje * a[i]

x = k//2
t = 10 ** 9 + 7
ans = x % t
print(ans)

