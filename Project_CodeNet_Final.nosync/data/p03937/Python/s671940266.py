H,W = map(int,input().split())
list1 =[]
count = 0
for i in range(H):
  a = list(input())
  list1.append(a)
for i in range(H):
  for j in range(W):
    if list1[i][j] == '#':
      count +=1
if count == H +W -1:
  print('Possible')
else:
  print('Impossible')