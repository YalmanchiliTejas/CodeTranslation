N = int(input())
A = list(map(int, input().split()))
mod = 10**9+7
sum = 0
sum_1 = 0

for i in range(N):
    sum += A[i]%mod
sum = (sum**2)%mod

for j in range(N):
    sum_1 += (A[j]**2)%mod
sum2=sum-sum_1
if sum2<0:
    sum2+=mod
ans=(sum2*500000004)%mod
print(int(ans))
