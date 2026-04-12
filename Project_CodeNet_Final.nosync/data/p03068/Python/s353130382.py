N = int(input())
S = input()
s = S[int(input())-1]

ans = ""
for i in S:
  if i == s:
    ans += s
  else:
    ans += "*"
print(ans)
