n = int(input().strip())
s = []
for _ in range(n):
  s.append(input().strip())

a, z = ord('a'), ord('z')
for i in range(a, z+1):
  i = chr(i)
  mi = min(_s.count(i) for _s in s)
  print(i * mi, end='')
  for j in range(len(s)):
    s[j].replace(i, '')

print()