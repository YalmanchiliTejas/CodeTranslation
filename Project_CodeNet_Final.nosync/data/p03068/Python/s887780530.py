n = int(input())
s = input()
k = int(input())
t = s[k - 1]
res = ''
for i in range(n):
  if s[i] == t:
    res += s[i]
  else:
    res += '*'
print(res)