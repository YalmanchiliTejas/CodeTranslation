s = list(input())

s = list(set(s))
if len(s) == 2:
  print('Yes')
else:
  print('No')