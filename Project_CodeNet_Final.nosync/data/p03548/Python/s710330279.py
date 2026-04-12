import math
X,Y,Z = map(int,input().split())
X -= Z
ans = math.floor(X /(Y+Z))
print(ans)
