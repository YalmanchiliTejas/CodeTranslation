#文字列の入力
S = input()
 
#listを一文字ずつのlistに
S_list = list(S)
 
AorB = S_list[0]
counter = 0
for i in range(len(S_list)):
  if(AorB == S_list[i]):
    counter = counter + 1
 
if(counter == len(S_list)):
  print("No")
else:
  print("Yes")