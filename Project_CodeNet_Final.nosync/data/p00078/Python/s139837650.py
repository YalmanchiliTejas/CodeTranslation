while 1:
    n = input()
    if n == 0:
        break
    field = [[0] * n for _ in xrange(n)]
    cnt = 1
    x, y = n / 2, n / 2 + 1
    field[y][x] = cnt
    cnt += 1
    while cnt <= n ** 2:
        y = (y + 1) % n
        x = (x + 1) % n
        while field[y][x] > 0:
            y = (y + 1) % n
            x = (x - 1 + n) % n
        field[y][x] = cnt
        cnt += 1

    for i in xrange(n):
        print ''.join(map("{0:4}".format, field[i]))