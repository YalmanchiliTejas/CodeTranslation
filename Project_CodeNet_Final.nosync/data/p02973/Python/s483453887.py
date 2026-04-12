from bisect import *
n = int(input())
a = [int(input()) for i in range(n)]

color = [-a[0]]
for i in range(1,n):
    if -a[i] >= color[-1]:
        color.append(-a[i])
    else:
        idx = bisect_right(color,-a[i])
        color[idx] = -a[i]

print(len(color))