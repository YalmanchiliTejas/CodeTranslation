H,W=map(int,input().split())
A=[list(input()) for _ in range(H)]
h=0
w=0
ans="Possible"
for i in range(H):
  for j in range(W):
    if A[i][j]=="#":
      if (i==h and j-w<2) or (i-h<2 and j==w):
        h=i
        w=j
      else:
        ans="Impossible"
print(ans)
