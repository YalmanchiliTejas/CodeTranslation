a = int(input())
s = input()
b = int(input())
ans = ""
for i in range(a):
  if s[i] == s[b-1]:
    ans += s[i]
  else:
    ans += "*"
print(ans)