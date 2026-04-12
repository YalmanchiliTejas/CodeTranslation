s=str(input())
l=[]
for i in range(3):
  l.append(s[i])
if len(set(l))==1:
  print('No')
else:
  print('Yes')