n = int(input())
A = list(map(int, input().split()))
B = A[::-1]

mod_n = 10**9+7

cum_A = [0]
for i in range(n-1):
  cum_A.append(cum_A[i]+B[i])
  
ans = 0
cum_B = cum_A[::-1]
for i in range(n-1):
  ans += A[i]*cum_B[i]%mod_n
  
print(ans%mod_n)