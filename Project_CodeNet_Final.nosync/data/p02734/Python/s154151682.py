def main():
  N,S = map(int,input().split())
  A = list(map(int,input().split()))
  MOD = 998244353

  ans = 0
  q = [0 for _ in range(S+1)]
  for i in range(len(A)):
    q[0] += 1
    q[0] %= MOD
    q2 = q[:]
    for j in range(S):
      if j+A[i] <= S:
        q2[j+A[i]] += q[j]
        q2[j+A[i]] %= MOD
    q = q2[:]
    ans += q[S]
  #print(q)
  print(ans%MOD)
  
main()