import math
A,B,C,X,Y =map(int,input().split())
ans = 10**9
for c in range(max(2*X,2*Y)+1):
    ans = min(ans, A*max(0,math.ceil(X-c/2))+B*max(0,math.ceil(Y-c/2))+C*c)
print(ans)
    