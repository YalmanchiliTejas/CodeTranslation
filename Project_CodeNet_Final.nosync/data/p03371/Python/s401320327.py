
a_yen, b_yen, c_yen, x, y = map(int, input().split())

amax = x
bmax = y
cmax = max(x,y) * 2

nedan = 10**10

for i in range(cmax//2+1):
    c=i*2
    
    a=max(amax-c//2,0)
    b=max(bmax-c//2,0)
    
    yen = a_yen * a + b_yen * b +c_yen * c
    # print(a,b,c,yen)
    nedan = min(nedan,yen)

print(nedan)