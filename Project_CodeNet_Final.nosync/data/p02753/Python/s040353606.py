S = list(input())

countA = 0
countB = 0
for i in range(len(S)):
  if S[i] == "A":
    countA = countA + 1
  elif S[i] == "B":
    countB = countB + 1

if countA == 3 or countB == 3:
  print('No')
else:
  print('Yes')