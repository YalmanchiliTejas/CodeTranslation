import sys
input = sys.stdin.readline

A,B,C,X,Y = list(map(int,input().split()))
cost = A*X+B*Y
if X >= Y:
    maxXY = X
    maxAB = A
else:
    maxXY = Y
    maxAB = B
ans = cost
for xy in range(1,maxXY+1):
    nc =  2*C*xy +max(0,(X-xy))*A+max(0,(Y-xy))*B
    #print(nc,cost)
    if nc < cost: 
        ans = min(ans,nc)
print(ans)
    
