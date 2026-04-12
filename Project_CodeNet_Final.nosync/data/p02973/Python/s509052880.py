N=int(input())
A=[int(input()) for _ in range(N)]

import bisect
B=[A[N-1]]
for i in range(N-2,-1,-1):
    if A[i]>=B[-1]:
        B.append(A[i])
    else:
        B[bisect.bisect_right(B,A[i])]=A[i]

print(len(B))