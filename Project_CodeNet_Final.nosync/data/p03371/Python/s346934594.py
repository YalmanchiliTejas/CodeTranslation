def resolve():
    import sys
    input = sys.stdin.readline
    # 整数 1 つ
    # n = int(input())
    # 整数複数個
    a, b, c, x, y = map(int, input().split())
    # 整数 N 個 (改行区切り)
    # N = [int(input()) for i in range(N)]
    # 整数 N 個 (スペース区切り)
    # N = list(map(int, input().split()))
    # 整数 (縦 H 横 W の行列)
    # A = [list(map(int, input().split())) for i in range(H)]

    pizzamax = [x for x in range(max(x,y)+1)]
    pizzamax.sort(reverse=True)

    paymin = 5000 * 2 * 10**5
    for i in pizzamax:
        pay = 2 * i * c
        if i < x:
            pay += (x-i) * a
        if i < y:
            pay += (y-i) * b
        paymin = min(paymin, pay)

    print(paymin)
resolve()