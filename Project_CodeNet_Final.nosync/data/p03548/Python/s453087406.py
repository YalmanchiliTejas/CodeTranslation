x,a,b=map(int,input().split())
if x%(a+b) < b:
  print(x//(a+b)-1)
  exit()
print(x//(a+b))
