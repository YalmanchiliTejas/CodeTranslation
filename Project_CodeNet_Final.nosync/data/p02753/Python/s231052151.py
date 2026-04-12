s = input()
n = []
for i in s:
  n.append(i)
  
if 'A' not in n:
  print('No')
elif 'B' not in n:
  print('No')
elif 'A' and 'B' in n:
  print('Yes')