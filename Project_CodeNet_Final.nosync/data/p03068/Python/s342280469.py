n = int(input())
s = str(input())
k = int(input())
ans = ""

for l in s:
  if l != s[k-1]:
    l = "*"
  ans += l
print(ans)
  