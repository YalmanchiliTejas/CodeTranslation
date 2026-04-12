x,y,z=map(int,input().split())
for i in range(x):
  if x<(y+z)*i+z:
    print(i-1)
    break