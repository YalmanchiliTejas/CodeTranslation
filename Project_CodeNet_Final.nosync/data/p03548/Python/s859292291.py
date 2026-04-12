x,y,z=map(int,input().split())

ans=z
cnt=0
while True:
  if ans>x:
    break
  ans+=y+z
  cnt+=1
print(cnt-1)