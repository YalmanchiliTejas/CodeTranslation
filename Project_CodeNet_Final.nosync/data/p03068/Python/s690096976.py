n = int(input())
s = input()
k = int(input())
ans = ""
for i in s:
  if s[k-1] == i:
    ans += i
  else:
    ans += "*"
print(ans)