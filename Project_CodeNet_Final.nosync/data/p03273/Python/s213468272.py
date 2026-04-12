H,W=map(int,input().split())
board=[input() for _ in range(H)]

def transpose(b):
  L,C=len(b),len(b[0])
  ret=[]
  for c in range(C):
    s=''
    for l in range(L):
      s+=b[l][c]
    ret.append(s)
  return ret

tmp=transpose(board)
ans=[]
for l in tmp:
  if '#' in l:
    ans.append(l)

tmp=transpose(ans)
ans=[]
for l in tmp:
  if '#' in l:
    print(l)