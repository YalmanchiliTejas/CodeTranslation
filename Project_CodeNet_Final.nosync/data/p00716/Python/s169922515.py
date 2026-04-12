m = int(input())
for _ in range(m):
    s = int(input())
    y = int(input())
    n = int(input())
    a = 0
    for _d in range(n):
        t, p, b = map(float, input().split())
        tem = 0
        ts = s
        if t:
            for _y in range(y):
                ts += int(ts * p)
                ts -= b
            a = max(a, ts)
        else:
            tp = 0
            for _y in range(y):
                tp += int(ts * p)
                ts -= b
            a = max(a, ts + tp)
    print(int(a))
