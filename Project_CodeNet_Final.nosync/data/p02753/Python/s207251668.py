n=input()
cnta=0
cntb=0
for e in n:
  if e=="A":
    cnta+=1
  elif e=="B":
    cntb+=1
if cnta==0 or cntb==0:
  print('No')
else:
  print('Yes')