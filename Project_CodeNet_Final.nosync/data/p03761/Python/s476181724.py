n = int(input())

d = {}

for k in range(97, 97+26):
  d[chr(k)] = 51
  
for i in range(n):
  s = str(input())
  for j in range(97,97+26):
    d[chr(j)] = min(d[chr(j)], s.count(chr(j)))

ans = ''
for k, v in d.items():
  ans += k*v
print(''.join(sorted(ans)))