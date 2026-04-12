import sys

n = int(input())
s = input()

array = [[True, True], [True, False], [False, False], [False, True]]

for i in range(1, n):
  for v in array:
    flag = ((s[i] == 'o') == v[i])
    v.append((flag == v[i-1]))
    
for v in array:
  flag1 = (v[1] == v[-2])
  flag2 = ((s[0] == 'o') == v[0])
  flag = (flag1 == flag2)
  
  if v[0] == v[-1] and flag:
    for c in v[0:len(v)-1]:
      if c:
        print('S', end='')
      else:
        print('W', end='')
        
    print()
    
    sys.exit(0)
    
print(-1)