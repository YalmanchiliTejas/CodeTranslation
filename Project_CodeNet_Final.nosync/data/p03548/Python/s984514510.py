import math
X,Y,Z=map(int,input().split())
ans=0

ans=math.floor((X-Z)/(Y+Z))
print(ans)