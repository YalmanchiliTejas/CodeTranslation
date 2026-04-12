n = int(input())
s = input()
key = s[int(input())-1]
ans = ''
for i in range(n):
  if s[i] == key:
    ans += s[i]
  else:
    ans += '*'
print(ans)