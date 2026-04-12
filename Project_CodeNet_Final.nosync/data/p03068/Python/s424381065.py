n = int(input())
s = input()
k = int(input())
ans = ""
t = s[k-1]
for i in s:
  if i == t:
    ans += t
  else:
    ans += "*"
print(ans)