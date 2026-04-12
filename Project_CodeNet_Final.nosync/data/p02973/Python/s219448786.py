n = int(input())
A = [int(input()) for _ in range(n)]

A.reverse()

import bisect
B = [10**18]
for a in A:
    i = bisect.bisect_right(B, a)
    if 0 <= i < len(B):
        B[i] = a
    else:
        B.append(a)
print(len(B))