n = int(input())
s = [list(input()) for _ in range(n)]
ans = ""
for j in [chr(i) for i in range(97, 97+26)]:
  flag = float("inf")
  for k in range(n):
    flag = min(flag,s[k].count(j))
  ans += j*flag
print(ans)