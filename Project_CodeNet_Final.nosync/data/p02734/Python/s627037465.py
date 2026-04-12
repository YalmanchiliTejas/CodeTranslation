N, S = map(int, input().split())
A = list(map(int, input().split()))
MOD = 998244353

DP = [0 for s in range(S+1)]
ans = 0
for i in range(N):
  a = A[i]
  for s in range(S,-1,-1):
    if s+a <= S:
      DP[s+a] += DP[s]
  if a <= S:
    DP[a] += i+1 #始点がiの列
  ans += DP[S]
  #print(DP, ans)
  
print(ans % MOD)
  
    
  