h,w=map(int,input().split())
maze=[]
for i in range(h):
  x=list(input())
  if x.count('#')!=0:
    maze.append(x)
  else:
    h-=1
    
ans=['' for i in range(h)]
  
for i in range(w):
  cnt=0
  for j in range(h):
    if maze[j][i]=='#':
      cnt+=1
  if cnt!=0:
    for k in range(h):
      ans[k]+=maze[k][i]
  else:
    w-=1
      
for i in range(h):
  print(ans[i])
    
  
