#6484898
from bisect import bisect
N= int(input())
A = []
for i in range(N):
    t = int(input())
    A.append(t)

D = [1]*(N+1)
D[0] = -10**10
for a in A:
    idx = bisect(D, -a)
    D[idx] = min(D[idx], -a)
print(bisect(D, 0)-1)