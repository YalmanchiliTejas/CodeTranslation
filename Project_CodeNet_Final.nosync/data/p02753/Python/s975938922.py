a=list(input())
if all([i=='A' for i in a]) or all([i=='B' for i in a]):
  print('No')
else:
  print('Yes')