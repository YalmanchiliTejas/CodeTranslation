N=int(input())
S=input()
K=int(input())-1
ans=""
for s in S:
  if S[K] != s:
    ans += "*"
  else:
    ans += s
print(ans)