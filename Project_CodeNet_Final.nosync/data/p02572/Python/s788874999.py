N=int(input())
*A,=map(int,input().split())
mod = 10**9+7

cum=[0]
for i in range(N):
  cum.append(cum[-1]+A[i])
  
ans = 0
for i in range(N-1):
  ans += A[i]*(cum[-1]-cum[i+1])
  ans %= mod
  
print(ans)