# coding: utf-8
while True:
    n = int(input())
    if n == 0:
        break
    t = 0
    ma = 0
    mi = 1000
    for i in range(n):
        s = int(input())
        t += s
        if(s > ma):
            ma = s
        if(s < mi):
            mi = s
    print((t - ma - mi) // (n - 2))