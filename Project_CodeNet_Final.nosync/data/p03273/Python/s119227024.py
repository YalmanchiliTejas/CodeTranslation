h,w = map(int,input().split())
a = [ input() for i in range(h)]

b = []
for i in range(h):
  if a[i].count('.') != w:
    b.append(a[i])
  else:
    h -= 1

c = [''] * h
for i in range(w):
  x = [row[i] for row in b] 
  if x.count('.') != h:
    for j in range(h):
      c[j] = c[j] + x[j]
    
for i in c:
  print(i)
  