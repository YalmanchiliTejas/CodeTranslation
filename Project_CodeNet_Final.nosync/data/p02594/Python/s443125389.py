import sys
def Ii():return int(sys.stdin.readline())
def Mi():return map(int,sys.stdin.readline().split())
def Li():return list(map(int,sys.stdin.readline().split()))
x = Ii()
if x >= 30:
  print('Yes')
else:
  print('No')