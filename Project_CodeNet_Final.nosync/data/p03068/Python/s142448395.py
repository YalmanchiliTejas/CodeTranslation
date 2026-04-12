n = int(input())
s = input()
k = int(input())
res = ''
for i in range(n):
  res += s[i] if s[i] == s[k-1] else '*'
print(res)