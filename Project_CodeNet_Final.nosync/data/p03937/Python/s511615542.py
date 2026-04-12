H,W=map(int,input().split())
gy,gx=H-1,W-1
grid=["" for i in range(H)]
touched=0
for i in range(H):
  grid[i]=input()
  touched+=grid[i].count("#")

if touched!=(H+W-1):
  print("Impossible")
  exit(0)

stack=[]
stack.append([0,0])
goal=False
while stack:
  v=stack.pop()
  y=v[0]
  x=v[1]
  if y==gy and x==gx:
    goal=True
    break
  if grid[y][x]==".":
    continue
  if y+1<H:
    stack.append([y+1,x])
  if x+1<W:
    stack.append([y,x+1])
    
print(("Impossible","Possible")[goal])