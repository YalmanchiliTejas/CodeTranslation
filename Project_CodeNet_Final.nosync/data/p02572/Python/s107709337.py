N = int(input())
A = list(map(int, input().split()))
mod = 10**9+7
k = int((10**9 + 8)/2)
sum = 0
sum_1 = 0

for i in range(N):
    sum += A[i]
sum = (sum**2)%mod

for j in range(N):
    sum_1 += A[j]**2
sum_1 = (sum_1)%mod

ans = sum - sum_1
ans = (ans*k)%mod

print(ans)
