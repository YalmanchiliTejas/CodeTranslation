s = input()

a = s[0]

flag = False
for i in range(1, 3):
  if s[i] != a:
    flag = True
    break
    
if flag:
  print('Yes')
else:
  print('No')
