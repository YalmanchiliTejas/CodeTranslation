a,b,c,x,y = map(int,input().split())
price = 10**10
for k in range(10**5+1):
    re = 2*c*k + max(0,x-k)*a + max(0,y-k)*b
    price = min(re,price)
print(price)