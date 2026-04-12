N,K = map(int, raw_input().split())
ans = 0
if K==0:
  ans = N*N
else:
  for b in range(K+1,N+1):
    ans += N/b*(b-K) + max(0, N%b-K+1)
print ans
