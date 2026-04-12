X,Y,Z = map(int,input().split())

def solve(x,y,z):
  cnt = 0
  x -= z
  while True:
    x -= y + z
    if x >= 0:
      cnt += 1
    else:
      return cnt
    
print(solve(X,Y,Z))