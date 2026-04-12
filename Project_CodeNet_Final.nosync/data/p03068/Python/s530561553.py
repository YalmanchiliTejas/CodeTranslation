n = int(input())
s = str(input())
num = int(input())
key = s[num-1]
ans = ""
for i in range(n):
  if s[i] != key:
    ans += "*"
  else:
    ans += key
print(ans)