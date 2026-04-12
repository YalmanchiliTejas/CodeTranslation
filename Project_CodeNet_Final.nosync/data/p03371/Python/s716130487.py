A,B,C,X,Y=map(int,input().split())

price=1000000000
for p in range(0,max(X,Y)*2+1,2):
    q=max(0,X-p//2)
    r=max(0,Y-p//2)
    if price>p*C+q*A+r*B:
        price=p*C+q*A+r*B
print(price)