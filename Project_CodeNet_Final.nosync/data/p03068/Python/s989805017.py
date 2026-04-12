n = int(input())
S = input()
k = int(input())
ans = ""
for i in range(n):
  if i != k - 1:
    if S[i] != S[k - 1]:
      ans += "*"
    else:
      ans += S[i]
  else:
    ans += S[i]
print(ans)