def f(a, b, c, x):
    return (a * x + b) % c
while 1:
    n, a, b, c, x = map(int, raw_input().split())
    if n == 0:
        break
    t = 0
    Y = map(int, raw_input().split())
    idx = 0
    while t <= 10000 and idx < n:
        if Y[idx] == x:
            idx += 1
            if idx == n:
                break
        x = f(a, b, c, x)
        t += 1
    if t > 10000:
        print -1
    else:
        print t