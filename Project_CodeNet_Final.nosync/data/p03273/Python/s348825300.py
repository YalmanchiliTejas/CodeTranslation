h, w = map(int,input().split())
aList = []
for i in range(h):
  aList.append(list(input()))
for i in range(h-1,-1,-1):
  if aList[i].count('#') == 0:
    aList.pop(i)

aList = list(zip(*aList))
for i in range(w-1,-1,-1):
  if aList[i].count('#') == 0:
    aList.pop(i)

aList = list(zip(*aList))

for i in aList:
  print(''.join(i))
