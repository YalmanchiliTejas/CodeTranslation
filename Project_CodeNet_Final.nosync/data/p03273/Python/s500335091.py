import copy
H,W=map(int,input().split())
List = []
for i in range (H):
  List.append(list(input()))
flag = False
NewList = []
#横の列の確認
for i in range(H):
  for j in range(W):
    if List[i][j]== "#":
      flag = True
  if flag:
    NewList.append(List[i])
  flag = False
flag1 = [True]*W
#縦の列の確認
for i in range(W):
  for j in range(len(NewList)):
    if NewList[j][i]== "#":
      flag1[i] = False
      
for j in range(len(NewList)):
  for i in range(W-1,-1,-1):
    if flag1[i]:
      NewList[j].pop(i)    
  
resList=[""]*H
for i in range(len(NewList)):
  for j in range(len(NewList[i])):
    resList[i] += NewList[i][j]
for element in resList:
  print(element)