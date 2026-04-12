N = int(input())
S = input()
K = int(input())
ans = ''

for i in range(N):
  if S[K-1] != S[i]:
    ans += '*'
  else:
    ans += S[i]
  
print(ans)
