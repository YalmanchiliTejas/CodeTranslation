s=input()
flag=1
if s[0]=='A':
  for i in s:
    if i=='B':
      flag*=0
else:
  for i in s:
    if i=='A':
      flag*=0
if flag==0:
  print('Yes')
else:
  print('No')

