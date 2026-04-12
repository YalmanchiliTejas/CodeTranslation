N = int(input())
S = list(input())
K = int(input())

ans = ''
for i in range(N):
  if(S[i] != S[K-1]):
    ans += '*'
  else:
    ans += S[i]
print(ans)