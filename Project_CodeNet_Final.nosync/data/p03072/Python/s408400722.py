## -*- coding utf-8 -*-

N = int(input())
HN = list(map(int, input().split()))

h = 0
c = 0
for hi in HN:
    if hi >= h:
        c += 1
    h = max(h, hi)

print(c)