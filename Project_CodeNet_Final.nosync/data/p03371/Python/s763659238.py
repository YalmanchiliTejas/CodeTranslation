a,b,c,x,y = map(int,input().split())

ans = 10000000000000000000000000000

for i in range(max(x,y)+1):
    price = 2*i*c + max(0,x-i)*a + max(0,y-i)*b
    
    if ans > price:
        ans = price
    
    else:
        continue
print(ans)