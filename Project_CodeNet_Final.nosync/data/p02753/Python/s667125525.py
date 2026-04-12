s = input()
for i in range(0,2):
  if s[i] != s[i+1]:
    print('Yes')
    break
else:
  print('No')