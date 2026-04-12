H,W=map(int,input().split())
A=[list(input()) for i in range(H)]
cnt=0
for h in range(H):
  for w in range(W):
    if A[h][w]=='#':
      cnt+=1
    
if cnt==H+W-1:
  print('Possible')
else:
  print('Impossible')