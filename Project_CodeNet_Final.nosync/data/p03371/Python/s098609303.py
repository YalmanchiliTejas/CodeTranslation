A,B,C,X,Y = map(int,input().split())
achete_A = 0
achete_B = 0
price = 10**100
C = 2 * C #=A,B
for i in range(0,10**5+1):
    price = min(price,i*C + A*max(0,X-i) + B * max(0,Y-i))
print(price)