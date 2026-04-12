# -*- coding: utf-8 -*-

n = int(input())
xx = list([i, x] for i, x in enumerate(map(int, input().split())))
xx.sort(key=lambda x: x[1])

mid1 = xx[n // 2][1]
mid2 = xx[n // 2 - 1][1]
for i in range(n // 2):
    xx[i][1] = mid1
for i in range(n // 2, n):
    xx[i][1] = mid2

xx.sort()
print('\n'.join(str(x[1]) for x in xx))
