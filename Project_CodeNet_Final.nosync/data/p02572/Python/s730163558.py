N = int(input())
A = list(map(int, input().split()))

MOD  = 10**9 + 7

l = [0]*(N)
for i in range(N-1):
  l[i+1] += (l[i] +  A[i])%MOD
  
#print(l)

ans = 0
for i in  range(N-1):
  ans += (A[N-1-i] * l[N-1-i])%MOD
  
print(ans%MOD)