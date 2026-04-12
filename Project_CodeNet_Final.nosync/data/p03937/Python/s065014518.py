H,W=map(int,input().split())
M=[input() for x in range(H)]
cnt=0
for i in range(H):
  for j in range(W):
    if M[i][j]=="#":
      cnt+=1
if cnt==H+W-1:
  print("Possible")
else:
  print("Impossible")