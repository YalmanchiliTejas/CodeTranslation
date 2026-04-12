import bisect
import sys
input = sys.stdin.readline
N = int(input())
A = []
for n in range(N):
    A.append(int(input()))
A = A[::-1]
INF = int(1e+9 + 10)
lis = [INF] * N
for n in range(N):
    i = bisect.bisect(lis, A[n])    
    lis[i] = A[n]
print (bisect.bisect_left(lis, INF))