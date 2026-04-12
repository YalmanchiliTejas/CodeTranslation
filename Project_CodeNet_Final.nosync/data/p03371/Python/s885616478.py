A,B,C,X,Y = (int(X) for X in input().split())
MINPrice = pow(10,9)
for ABP in range(0,2*max(X,Y)+1,2):
    Price = A*max(0,(X-ABP//2))+B*max(0,(Y-ABP//2))+C*ABP
    if Price<=MINPrice:
        MINPrice = Price
print(MINPrice)