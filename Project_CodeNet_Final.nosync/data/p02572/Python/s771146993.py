N = int(input())
A = list(map(int,input().split()))

tmp = [0]*N
tmp2 = [0]*N
tmp2[0] = A[0]

for i in range(1,N):
    tmp2[i] = A[i] + tmp2[i-1]
sum_A = sum(A)

for i in range(N):
    tmp[i] = sum_A - tmp2[i]

ans = 0
mod = 10**9+7
for i in range(N):
    ans += (A[i]*tmp[i])%mod
    ans = ans%mod
    
print(ans)