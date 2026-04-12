N = int(input())
S = input()
K = int(input())

n = S[K-1]
ans = ""
for i in range(N):
  if S[i] != n:
    ans += "*"
  else:
    ans += S[i]
print(ans)