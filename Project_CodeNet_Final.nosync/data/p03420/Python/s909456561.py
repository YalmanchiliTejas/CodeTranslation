N, K = map(int, input().split())

ans = 0
for b in range(K+1,N+1):
  if N%b==0:
    ans += (N//b)*(b-K)
  else:
    ans += (N//b)*(b-K)+max(N%b-K+1,0) if K!=0 else (N//b)*(b-K)+(N%b)
#  print(ans)
print(ans)