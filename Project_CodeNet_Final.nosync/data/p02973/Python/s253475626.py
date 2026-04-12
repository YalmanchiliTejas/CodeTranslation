import bisect
n = input()
aa = []
xx = [-input()]
for _ in xrange(n - 1):
    aa.append(-input())
for a in aa:
    if a >= xx[-1]:
        xx.append(a)
    else:
        i = bisect.bisect_right(xx, a)
        if i == len(xx):
          i -= 1
        xx[i] = a
print len(xx)