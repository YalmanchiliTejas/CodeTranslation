# abc95 c
a,b,c,x,y = map(int, input().split())
cost = 0
# 両方のピザをmin(x,y)枚買うー＞足りない方をabs(x-y)枚買う
if a+b >= 2*c:
    cost += 2*c*min(x,y)
else:
    cost += (a+b)*min(x,y)

if x-y == 0:
    print(cost)
else:
    if x-y >0:
        if a > 2*c:
            cost += 2*c*(x-y)
        else:
            cost += a*(x-y)
    else:
        if b > 2*c:
            cost += 2*c*abs(x-y)
        else:
            cost += b*abs(x-y)
        
    print(cost)
    