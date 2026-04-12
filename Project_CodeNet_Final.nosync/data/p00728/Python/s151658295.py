while True:
    min = 1000
    max = 0
    sum = 0
    
    n=int(input())
    if n ==0:
        break
    for i in range(n):
        s=int(input())
        if s < min:
            min = s
        if s > max:
            max = s
        sum += s
    print((sum - min - max)//(n - 2))

