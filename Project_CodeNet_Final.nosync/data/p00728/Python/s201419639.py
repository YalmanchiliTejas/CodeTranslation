while 1:
    n = int(input())
    if n == 0:
        break
    point = [int(input()) for i in range(n)]
    point.sort()
    Sum = 0
    hito = 0
    for i in range(1,n-1):
        Sum += point[i]
        hito += 1
    ans = Sum // hito
    print(ans)


