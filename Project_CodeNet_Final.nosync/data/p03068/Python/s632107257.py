N = int(input())
S = str(input())
K = int(input())
t = S[K-1]
ans = ""
for i in range(N):
  if S[i] == t:
    ans += S[i]
  else:
    ans += "*"
print(ans)