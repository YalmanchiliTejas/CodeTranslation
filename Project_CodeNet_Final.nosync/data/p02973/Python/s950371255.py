N = int(input())
L = []
from bisect import bisect_right
for _ in range(N):
    u = -int(input())
    index = bisect_right(L,u)
#    print(index)
    if index == len(L):
        L.append(u)
    else:
        L[index ] = u
print(len(L))
