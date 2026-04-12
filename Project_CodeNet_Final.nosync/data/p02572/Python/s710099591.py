import copy

N = int(input())
A = list(map(int,input().split()))
mod = 10**9+7

partial_sum = copy.deepcopy(A)
sum_now = A[N-1]
for j in range(N-2,-1,-1):
    sum_now = int((sum_now+A[j])%mod)
    partial_sum[j] = sum_now
res = 0
for i in range(N-1):
    res = (res + (A[i]*partial_sum[i+1])%mod) %mod
print(int(res))
