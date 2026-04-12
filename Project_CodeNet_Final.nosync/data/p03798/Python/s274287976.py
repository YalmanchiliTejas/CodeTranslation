n = int(input())
s = str(input())

l = ['SS', 'SW', 'WS', 'WW']

for i in range(4):
  ans = l[i]
  for j in range(1, n):
    if ans[j] == 'S' and s[j] == 'o':
      if ans[j-1] == 'S':
        ans += 'S'
      else:
        ans += 'W'
    elif ans[j] == 'S' and s[j] == 'x':
      if ans[j-1] == 'S':
        ans += 'W'
      else:
        ans += 'S'
    elif ans[j] == 'W' and s[j] == 'o':
      if ans[j-1] == 'S':
        ans += 'W'
      else:
        ans += 'S'
    else:
      if ans[j-1] == 'S':
        ans += 'S'
      else:
        ans += 'W' 
  flag = 0
  if ans[-1] == ans[0]:
    if ans[0] == 'S' and s[0] == 'o':
      if ans[-2] == ans[1]:
        flag = 1
    elif ans[0] == 'W' and s[0] == 'o':
      if ans[-2] != ans[1]:
        flag = 1
    elif ans[0] == 'S' and s[0] == 'x':
      if ans[-2] != ans[1]:
        flag = 1
    else:
      if ans[-2] == ans[1]:
        flag = 1
  if flag == 1:
    print(ans[:-1])
    exit()
else:
  print('-1')
  
 
  
  