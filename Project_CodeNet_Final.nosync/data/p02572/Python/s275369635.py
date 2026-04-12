import numpy as np

n = int(input())

a = list(map(int, input().split()))

s = [0]

for i in a:
  s.append(s[-1]+i)

ans = 0
for i in range(len(a)):
  ans += a[i]*s[i]

print(ans%(10**9+7))