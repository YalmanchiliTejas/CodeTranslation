n = int(input())
s = input()
k = int(input()) - 1
ans = ''
for i in range(n):
  if s[i] == s[k]:
    ans = ans + s[k]
  else:
    ans = ans + '*'
print(ans)