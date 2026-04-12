import bisect

n = int(input())
a = [int(input()) for i in range(n)]

b = []
for i in range(n):
    k = bisect.bisect(b,-a[i])
    if k == len(b):
        b.append(-a[i])
    else:
        b[k] = -a[i]

print(len(b))