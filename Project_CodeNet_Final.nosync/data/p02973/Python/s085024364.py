n=int(input())
a=[int(input()) for _ in range(n)]
from bisect import bisect
b=[]
for i in a:
    j=bisect(b,-i)
    if len(b)==j:
        b.append(-i)
    else:
        b[j]=-i

print(len(b))