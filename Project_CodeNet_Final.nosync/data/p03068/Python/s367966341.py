n = int(input())
s = str(input())
k = int(input())
z = s[k - 1]
y = ''
for i in range(n):
  if s[i] != z:
    y += '*'
  else:
    y += s[i]
print(y)