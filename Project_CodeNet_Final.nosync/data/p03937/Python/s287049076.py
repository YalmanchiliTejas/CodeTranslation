h,w = map(int,input().split())
maze = [list(input()) for _ in range(h)]

check = [['.'] * w for _ in range(h)]
check[0][0] = '#'

def dfs(x,y):
  global flag,check
  if x == h-1 and y == w-1:
    flag = True
    return
  if x != h-1 and maze[x+1][y] == '#':
    check[x+1][y] = '#'
    dfs(x+1,y)
    return
  if y != w-1 and maze[x][y+1] == '#':
    check[x][y+1]= '#'
    dfs(x,y+1)
    return
  return
dfs(0,0)
if maze == check:
    print('Possible')
else:
    print('Impossible')
