X,Y,Z = map(int,input().split())
for i in range(1,100000):
  if Y*i+Z*(i+1) > X:
    print(i-1)
    break