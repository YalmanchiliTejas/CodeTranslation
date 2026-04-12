from collections import Counter

n = int(raw_input())
cls = [Counter(raw_input()) for _ in range(n)]
for i in range(1,n):
    cls[0] = cls[0] & cls[i]
print ''.join(sorted(list(cls[0].elements())))
