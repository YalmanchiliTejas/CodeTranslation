X,Y,Z=map(int,input().split())

for i in range(1,10**9):
  width=i*Y+(i+1)*Z
  if width>X:
    break

print(i-1)