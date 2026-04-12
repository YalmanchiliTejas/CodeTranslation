X,Y,Z=map(int,input().split())
cnt=0

while(1):
    if(X<Y*cnt+Z*(cnt+1)):
        break
    cnt+=1

print(cnt-1)