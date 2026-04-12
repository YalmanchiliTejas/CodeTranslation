A,B,C,X,Y=map(int,input().split())

ans = A*X + B*Y
tmp = A*X + B*Y
x = X
y = Y
z = 0

while x >= 0 or y >= 0:
    tmp = A*max(0,x) + B*max(0,y) + C*z
    ans = min(ans,tmp)
    x=x-1
    y=y-1
    z=z+2

print(ans)