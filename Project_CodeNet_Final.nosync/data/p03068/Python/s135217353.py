n = int(input())
s = input()
k = int(input())-1
res = ''
for i in range(n):
  if s[i] == s[k]:
    res += s[i]
  else:
    res += '*'
print(res)