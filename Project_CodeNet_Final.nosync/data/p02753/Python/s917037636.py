N=input()
if  all(n=='A'  for n in N):
  print('No')
elif all(n=='B' for n in N):
  print('No')
else:
  print('Yes')