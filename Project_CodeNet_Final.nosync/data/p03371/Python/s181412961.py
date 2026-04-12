A,B,C,X,Y =[int(i) for i in input().split()]

ans = A*X+B*Y
Z=0
while True:
    X=max(X-1,0)
    Y=max(Y-1,0)
    Z=Z+2
    price=A*X+B*Y+C*Z
    #print(X,Y,Z,price)
    if ans > price:
        ans=price
    if X==0 and Y==0:
        break


print(ans)