X, Y, Z = map(int, input().split())
def solve():
  for i in range(int(X/Y)+2):
    if(X < i*Y+(i+1)*Z):
      print(i-1)
      return

solve()