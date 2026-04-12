def check_range(xy, n):
    for i in range(2):
        if xy[i] == -1:
            xy[i] = n - 1
        elif xy[i] == n:
            xy[i] = 0
    return xy

while True:
    n = int(input())
    if n == 0:
        break
    ms = [[0 for i in range(n)] for j in range(n)]
    xy = [n//2, n//2 - 1]
    i = 1
    while i <= n*n:
        if ms[xy[1]][xy[0]] != 0:
            xy[0] -= 1
            xy[1] -= 1
            xy = check_range(xy, n)
            continue
        ms[xy[1]][xy[0]] = i
        xy[0] += 1
        xy[1] -= 1
        xy = check_range(xy, n)
        i += 1
    for i in range(n):
        s = ""
        for j in range(n):
            s += "{0:>4}".format(str(ms[n - i - 1][j]))
        print(s)

