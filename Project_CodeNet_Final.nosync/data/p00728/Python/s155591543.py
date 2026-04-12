while 1:
    n = int(input())
    if n == 0:
        break
    
    s = [int(input()) for i in range(n)]
    s.sort()
    x = sum(s) - (s[0] + s[-1])
    print(x // (n - 2))
