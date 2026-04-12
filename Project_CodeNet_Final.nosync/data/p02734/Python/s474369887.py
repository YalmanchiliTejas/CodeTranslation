N,S = map(int,input().split())
A = list(map(int,input().split()))
MOD=998244353

Q = [0 for _ in range(S+1)]
ans = 0
for i in range(N):
  Q[0] += 1
  Q2 = [0 for _ in range(S+1)]
  for j in range(S+1):
    Q2[j] += Q[j]%MOD
    if j+A[i] <= S: #(1+x^A[i])をかけてもx^sを超えないときに限り。
      Q2[j+A[i]] += Q[j]%MOD
  Q = Q2
  ans += Q[S]%MOD
ans = ans %MOD
print(ans)