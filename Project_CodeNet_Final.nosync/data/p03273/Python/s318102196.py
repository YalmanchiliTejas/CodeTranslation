import numpy as np

h,w=input().split()
h=int(h)
w=int(w)

list1 =[input() for i in range(h)]
#print(list1)

list2=[]
for i in range(h):
  if list1[i].count('#') > 0:
    list2.append(list1[i])
#print(list2)
list2_num=len(list2)

list4=[]
for i in range(list2_num):
  list3=(list(list2[i]))
  list4.append(list3)
#print(list4)
list4=np.array(list4).T
#print(list4)

list4=list4.tolist()
list5=[]
for i in range(w):
  if list4[i].count('#') > 0:
    list5.append(list4[i])
#print(list5)

list5=np.array(list5).T
#print(list5)
list5=list5.tolist()
#print(list5)
for i in range(len(list5)):
  for j in range(len(list5[0])):
    print(list5[i][j], end='')
  print('')