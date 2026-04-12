X,Y,Z=map(int,input().split())
ans=0
K=Z
while(True):
    if K+Y+Z>X:
        break
    K+=Y+Z
    ans+=1
print(ans)