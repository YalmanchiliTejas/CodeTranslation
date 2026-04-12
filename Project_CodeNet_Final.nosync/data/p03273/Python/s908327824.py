import numpy as np
h,w=map(int,input().split())
maze=[]
for i in range(h):
  s=list(input())
  if s.count(".")==len(s):continue
  maze.append(s)
maze=np.array(maze).T
ans=[]
for i in range(10**5):
  try:q=maze[i]
  except:break  
  if all(x=="." for x in q):
      continue
  ans.append(q)
ans=((np.array(ans).T).tolist())
for i in ans:
  for j in i:
    print(j,end="")
  print()