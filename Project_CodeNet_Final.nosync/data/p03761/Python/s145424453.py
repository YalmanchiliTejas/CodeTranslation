n = int(input())
s = [input() for i in range(n)]
query ='abcdefghijklmnopqrstuvwxyz'
a = []
for i in query:
  ct = 999999999999999
  for j in range(n):
   ct = min(ct,s[j].count(i))
  if ct>0:
   a.append(i*ct)

print(''.join(a))