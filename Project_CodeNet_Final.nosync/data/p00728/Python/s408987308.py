i = 0
while True:
    
    n = int(input())
    if n == 0:
        break

    x = 0
    b = -1
    c = 1001
    for i in range(n):
        a = int(input())
        x += a
        b = max(b, a)
        c = min(a, c)
        y = (x-b-c)//(n-2)
        
    i += 1

    print(y)
