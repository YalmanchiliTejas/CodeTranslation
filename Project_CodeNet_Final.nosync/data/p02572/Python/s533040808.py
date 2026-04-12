N = int(input())
A = [int(x) for x in input().split()]
 
partial_sum = A.copy()
sum_now = A[N-1]
for j in range(N-2,-1,-1):
    sum_now = int((sum_now+A[j])%(10**9+7))
    partial_sum[j] = sum_now
res = 0
for i in range(N-1):
    res = (res + (A[i]*partial_sum[i+1])%(10**9+7)) %(10**9+7)
print(int(res))