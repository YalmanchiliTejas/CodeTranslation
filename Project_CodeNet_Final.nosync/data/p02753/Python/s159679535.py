s=input()
z=0
for i in range(2):
  if s[i]==s[i+1]:
    z+=1
if z==2:
  print('No')
elif z<2:
  print('Yes')