while True:
    n = int(input())
    if n ==0:
        break
    
    x = [int(input()) for i  in range(n)]
    x.sort()
    scr = (sum(x)-max(x)-min(x))//(n-2)
    print(scr)

