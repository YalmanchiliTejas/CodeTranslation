def solve():
    A,B,C,X,Y = map(int, input().split())
    ret = 0
    max_pizza = max(X,Y)
    min_pizza = min(X,Y)
    if A+B >= 2*C:
        ret += min_pizza*2*C
    else:
        ret += min_pizza*(A+B)
        
    max_price = B if X < Y else A
    if max_price <= 2*C:
        ret += (max_pizza - min_pizza)*max_price
    else:
        ret += 2*C*(max_pizza - min_pizza)
    
    print(ret)
    
solve()