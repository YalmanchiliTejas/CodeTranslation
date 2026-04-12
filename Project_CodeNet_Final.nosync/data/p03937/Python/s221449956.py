h,w=map(int,input().split())
bd = [list("."+input()+".") for i in range(h)]
bd.insert(0,["."]*(w+2))
bd.append(["."]*(w+2))
stack=[(1,1)]
while(stack):
  i,j=stack.pop()
  if i == h and j == w:
    bd[i][j]="."
    break
  if bd[i+1][j] == bd[i][j+1]:
    print("Impossible")
    exit()
  if bd[i-1][j] == "#" or bd[i][j-1] == "#":
    print("Impossible")
    exit()
  if bd[i+1][j] == "#":
    stack.append((i+1,j))
  if bd[i][j+1] == "#":
    stack.append((i,j+1))
  bd[i][j] = "."
if bd == [["." for i in range(w+2)] for j in range(h+2)]:
  print("Possible")
else:
  print("Impossible")