s=input()
a,b=0,0
for i in range(3):
  if(s[i]=='A'):
    a+=1
  else:
    b+=1
if(a>0 and b>0):
  print('Yes')
else:
  print('No')
  