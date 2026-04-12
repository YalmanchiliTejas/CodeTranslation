n = int(input())
s = list(input())
k = int(input())
remain = s[k - 1]
if s[0] == remain:
  ans = remain
else:
  ans = "*"
for i_m in range(n - 1):
  i = i_m + 1
  if s[i] == remain:
    ans += remain
  else:
    ans += "*"
print(ans)