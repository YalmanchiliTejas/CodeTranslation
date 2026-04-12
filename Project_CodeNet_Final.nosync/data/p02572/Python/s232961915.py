from copy import deepcopy

N = int(input())
A = list(map(int,input().split()))

B = deepcopy(A)

for i in range(N-1):
    B[i+1] += B[i]

ans = 0

for i in range(N):
    ans += A[i]*(B[-1]-B[i])

print(ans%(10**9+7))