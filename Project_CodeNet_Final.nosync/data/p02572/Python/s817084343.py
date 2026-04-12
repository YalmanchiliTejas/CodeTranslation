mod = 1000000007
N = int(input())
ruiseki = []
A = list(map(int, input().split()))
sum = 0

for i in range(N):
  sum += A[i]
  sum = sum%mod

ruiseki.append(sum - A[0])
if(ruiseki[0] < 0): ruiseki[0] += mod

for i in range(1,N-2):
  ruiseki.append(ruiseki[i-1] - A[i])
  if(ruiseki[i] < 0): ruiseki[i] += mod

ans = 0

for i in range(0,N-2):
  ans += A[i]*(ruiseki[i])%mod

ans += (A[N-2]%mod)*(A[N-1]%mod)%mod
ans = ans%mod
print(ans)