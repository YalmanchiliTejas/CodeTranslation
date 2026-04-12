while True:
    n = int(input())
    if n == 0:
        break
    
    a = [int(input()) for i in range(n)]
    a.sort()
    x = sum(a) - a[0] - a[-1]
    print(x // ( n- 2))
