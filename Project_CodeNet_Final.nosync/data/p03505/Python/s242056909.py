import math

k, a, b = map(int, input().split())
inc = a - b
if k <= a:
    print(1)
elif inc < 0:
    if k <= a:
        print(1)
    else:
        print(-1)
elif inc == 0:
    print(-1)
else:
    from decimal import *
    getcontext().prec = 500
    print(math.ceil(Decimal(k-a) / Decimal(inc))*2+1)




