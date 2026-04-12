import bisect

n = int(input())

c = []
for i in range(n):
    a = int(input())
    j = bisect.bisect_right(c, -a)
    if j == len(c):
        c.append(-a)
    else:
        c[j] = -a
print(len(c))