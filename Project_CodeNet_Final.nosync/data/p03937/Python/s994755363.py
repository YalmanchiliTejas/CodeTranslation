H,W=list(map(int, input().split()))
A=[list(input()) for _ in range(H)]
for i in range(2**(H+W)):
  L=[['.']*W for _ in range(H)]
  L[0][0]='#'
  c,d=0,0
  for j in range(H+W):
    if (i>>j)&1:
      c+=1
    else:
      d+=1
    if 0<=c<H and 0<=d<W:
      L[c][d]='#'
    else:
      break
  for k in range(H):
    if A[k]!=L[k]:
      break
  else:
    print('Possible')
    exit()
else:
  print('Impossible')