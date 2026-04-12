n = int(input())
s = input()
k = int(input())
d = s[k - 1]
ans = ''
for c in s:
  if c == d:
    ans += c
  else:
    ans += '*'
print(ans)