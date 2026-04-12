X,Y,Z=map(int,input().split())
W=Y+Z
cnt=0
X-=Z*2
while X>W:
    X-=W
    cnt+=1
if X>=Y:
    cnt+=1
print(cnt)
    