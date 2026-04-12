def solve():
    A, B, C, X, Y = map(int, input().split())
    C *= 2

    mn = float('inf')
    for i in range(max(X,Y)+1):
        price = 0
        price += C * i
        if Y - i > 0:
            price += B * (Y - i)
        
        if X - i > 0:
            price += A * (X - i)
        
        mn = min(price, mn)
    
    print(mn)

if __name__ == '__main__':
    solve()