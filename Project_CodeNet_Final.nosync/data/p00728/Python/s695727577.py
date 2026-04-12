while True:
    n = int(input())
    if n == 0:
        break
    MIN = 1000
    MAX = 0
    points = 0
    for i in range(n):
        p = int(input())
        if MIN > p:
            MIN = p
        if MAX < p:
            MAX = p
        points += p
    print((points - MIN - MAX) // (n - 2))

