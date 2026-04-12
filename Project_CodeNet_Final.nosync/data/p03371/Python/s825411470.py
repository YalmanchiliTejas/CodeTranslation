A,B,C,X,Y = map(int,input().split())

price = X * A + Y * B
for a in [0,abs(X-Y),X]:
    for b in [0,abs(X-Y),Y]:
        c = max(X-a,Y-b)*2
        price = min(price,a*A + b*B + c*C)

print(price)