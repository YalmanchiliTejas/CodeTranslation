rh=set("yuiophjklnm")
while 1:
  t=input()
  if t=="#":break
  c=0
  for (i,j) in enumerate(t):
    if i==0:
      if j in rh:
        r=True
      else:
        r=False
    else:
      if (j in rh and not r) or (not j in rh and r):
        c+=1
      r=j in rh
  print(c)
