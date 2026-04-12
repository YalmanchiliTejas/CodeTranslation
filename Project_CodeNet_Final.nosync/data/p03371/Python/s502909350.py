A,B,C,X,Y=map(int,input().split())

ans = A*X + B*Y
tmp = A*X + B*Y
x = X
y = Y
z = 0

while x >= 0 or y >= 0:
    if x<0 and y<0:
        tmp = C*z
    elif x<0:
        tmp = B*y + C*z
    elif y<0:
        tmp = A*x + C*z
    else:
        tmp = A*x + B*y + C*z
    ans = min(ans,tmp)
    x=x-1
    y=y-1
    z=z+2

print(ans)