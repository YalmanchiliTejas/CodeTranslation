S = input()
flag = False
for i in range(len(S)):
  if S[i] != S[0]:
    flag = True
if flag == True:
  print('Yes')
else:
  print('No')