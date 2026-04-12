H, W = map(int,input().split())
HW = [str(input()) for i in range(H)]

i = 0
while len(HW) > i:
  if "#" not in HW[i]:
    HW.pop(i)
    i -= 1
  i += 1  
  #print(HW)  
#print(HW)
clear_w = [0] * W
for i in range(len(HW)):
  for j in range(W):
    x = HW[i][j]
    if x == "#":
      clear_w[j] = 1
#print(clear_w)
 
for i in range(len(HW)):
  HW[i] = [HW[i][j] for j in range(W) if clear_w[j] == 1]
  
#print(HW)      
for i in range(len(HW)):
  for j in range(len(HW[i])):
    if j != len(HW[i]) - 1:
      print(HW[i][j], end = "")
    else:
      print(HW[i][j])