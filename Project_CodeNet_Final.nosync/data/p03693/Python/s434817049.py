import sys
input = sys.stdin.readline
#-------------
r,g,b = map(int,input().split())
#-------------
x = 100*r + 10*g + b
mod = x%4

if mod == 0:
  print("YES")
else:
  print("NO")