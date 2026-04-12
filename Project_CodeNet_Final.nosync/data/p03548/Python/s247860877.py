x,y,z=map(int,input().split())

cnt=0
tmp=0
while(1):
    tmp+=y+z
    if tmp>x-z:
        break
    cnt+=1

print(cnt)
