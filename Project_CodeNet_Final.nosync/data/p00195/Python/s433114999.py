def solve():
    from sys import stdin
    f_i = stdin
    
    while True:
        s1A, s2A = map(int, f_i.readline().split())
        
        if s1A == 0 and s2A == 0:
            break
        
        sales = [(s1A + s2A, 'A')]
        for shop in 'BCDE':
            cnt = sum(map(int, f_i.readline().split()))
            sales.append((cnt, shop))
        
        cnt, shop = max(sales)
        
        print(f"{shop} {cnt}")

solve()
