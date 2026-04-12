h,w= map(int,input().split())
l = list()
m = 0
for i in range(h):
  c = input()
  if "#" in c:
    b = [ w for w in range(len(c)) if c[w] == "#" ]
    l.append(b)
    if m < max(b) : m = max(b)
p = list()
for i in range(m) :
  for j in l:
    if i in j: break
  else:
    p.append(i)
for j in range(len(l)):
  for e in range(len(l[j])):
    cnt = 0
    for q in p:
      if l[j][e] > q : cnt += 1
    l[j][e]  = l[j][e]  - cnt
m = 0
for i in l:
  if m < max(i) : m = max(i)
for i in l:
  t = ""
  for j in range(m+1):
    if j in i : t = t + "#"
    else: t = t + "."
  print(t)