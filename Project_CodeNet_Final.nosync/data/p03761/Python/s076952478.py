n = int(input())
s = str(input())
l = [i for i in s]
for i in range(n-1):
  t = []
  s = str(input())
  for j in s:
    if j in l:
      t.append(j)
      l.remove(j)
  l = t
  
if l != []:
  l.sort()
  ans = ''.join(l)
  print(ans)