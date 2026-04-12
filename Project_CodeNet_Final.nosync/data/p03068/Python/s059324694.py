n = int(input())
s = input()
r = int(input())
a = s[r-1]
ans = ''
for i in range(n):
  if s[i] == a:
    ans += s[i]
  else:
    ans += "*"
print(ans)