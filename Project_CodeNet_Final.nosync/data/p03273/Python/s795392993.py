h,w=map(int,input().split())
slist=[input() for i in range(h)]
c=1
while c==1:
  c=0
  for i in range(h):
    s=slist[i]
    if "#" not in s:
      del slist[i]
      h -= 1
      c=1
      break
  if c==0:
    for i in range(w):
      li = [slist[j][i] for j in range(h)]
      if len(set(li))==1 and "." in li:
        for j in range(h):
          slist[j]=slist[j][:i]+slist[j][i+1:]
        c=1
        w -=1
        break
for i in range(h):
  print(slist[i])