import itertools
N = int(input())
A = list(map(int, input().split()))
ans = 0
sumall = 0
for j in range(N):
    sumall += A[j]
for i in range(N):
    ans += A[i]*(sumall-A[i])
    sumall = sumall - A[i]

print(ans % (10**9+7))