h, w=map(int, input().split())
a=[input() for _ in range(h)]
s=set()
t=set()
for i in range(h):
  if '#' in a[i]:
    s.add(i)
    for j in range(w):
      if a[i][j]=='#':
        t.add(j)
for i in s:
  l=''
  for j in t:
    l+=a[i][j]
  print(l)