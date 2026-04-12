MM = input().split()
A = int(MM[0])
B = int(MM[1])
list1 =[]
for i in range(A):
  aa = input()
  if '.'*B == aa:
    pass
  else:
    list1.append(list(aa))


for i in range(B):
  count = 0
  for j in range(len(list1)):
    if list1[j][i] == '#':
      count +=1
  if count == 0:
    for j in range(len(list1)):
     
      list1[j][i] = 'a'

for i in list1:
  if 'a' in i:
    i.remove('a')

for i in list1:
  for j in i:
    if j != 'a':
      print(j,end='')
  print()
    
  
               
    
  
               