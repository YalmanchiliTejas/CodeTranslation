H,W = map(int,input().split())
H_cnt = 0
maze = ["" for _ in range(W)]
maze_ok = [True]*W
for _ in range(H):
  m = input()
  if m != "."*W:
    for i in range(W):
      maze[i] += m[i]
  else:
    H_cnt += 1
for i in range(W):
  if maze[i]=="."*(H-H_cnt):
    maze_ok[i]=False

ans = ["" for _ in range(H-H_cnt)]
for i in range(H-H_cnt):
  for j in range(W):
    if maze_ok[j]:
      ans[i] += maze[j][i]

for a in ans:
  print(a)
                 
    
    
    
    
    
  
    


