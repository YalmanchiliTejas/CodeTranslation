h,w = map(int,input().split())
l = list(list(input()) for i in range(h))
for i in l:
  if i.count('.') ==w:
    i.clear()
l= [i for i in l if i!=[]]
#print(l)
t = len(l)
for i in range(w):
  if all (l[q][i]=="." for q in range(t)):
    for q in range(t):
      l[q][i] =""
if "" in l:
  for z in l:
    z.remove("")
for m in l:
  print("".join(m))

