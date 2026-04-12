while True:
    n = int(input())
    if n==0: 
        break
    l = []
    for i in range(n):
        x = int(input())
        l.append(x)
    l.sort()
    a = sum(l)-(max(l)+min(l))
    print(a//(n-2))
