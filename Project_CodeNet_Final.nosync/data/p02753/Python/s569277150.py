s=input()
a=0
for i in range(2):
  if s[i]==s[i+1]:
    a+=1
if a==2:
  print('No')
else:
  print('Yes')