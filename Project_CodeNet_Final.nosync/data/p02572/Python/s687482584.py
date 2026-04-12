def abc177c():
    n = int(input())
    a = list(map(int, input().split()))
    a_cum = [0] * n
    a_cum[-1] = a[-1]
    for i in range(n - 2, -1, -1):
        a_cum[i] = a_cum[i + 1] + a[i]
    total = 0
    for i in range(n - 1):
        total += a[i] * a_cum[i + 1]
    print(total % (pow(10,9)+7))

abc177c()