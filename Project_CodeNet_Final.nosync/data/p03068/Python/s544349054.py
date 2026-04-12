n = int(input())
s = input()
k = int(input())
keyword = s[k-1]
ans = ""
for i in s:
  if i == keyword:
    ans += i
  else:
    ans += "*"
print(ans)