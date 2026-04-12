while True:
    n = int(input())
    if n == 0:
        break
    data = [int(input()) for z in range(n)]
        
    a = min(data)
    b = max(data)
    c = sum(data) - a - b

    print(c//(n-2))
