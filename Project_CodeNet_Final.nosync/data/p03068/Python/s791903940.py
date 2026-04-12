N = int(input())
S = input()
K = int(input())
ans = ""
for i in S:
  if i == S[K-1]:
    ans += i
  else:
    ans += "*"
print(ans)