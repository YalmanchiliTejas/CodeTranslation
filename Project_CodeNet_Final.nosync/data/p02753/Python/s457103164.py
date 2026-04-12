S = input()
topOfS = S[0]
isPass = False
for i in S:
  if topOfS != i:
    isPass = True
    break
if isPass == True:
  print("Yes")
else:
  print("No")