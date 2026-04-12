N = int(input())
S = input()
K = int(input())
s = S[K-1]
ans = ""
for ss in S:
  if ss == s:
    ans += s
  else:
    ans += "*"
print(ans)