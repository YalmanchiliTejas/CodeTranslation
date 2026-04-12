import math

while 1:
    n, l, r = map(int, input().split())
    if (n, l, r) == (0, 0, 0): break
    aa = [int(input()) for _ in range(n)]
    koho = set([i for i in range(l, r + 1)])
    baisu = set()
    uru = set()
    for i, a in enumerate(aa):
        start = math.ceil(l / a) * a
        for k in range(start, r + 1, a):
            baisu.add(k)
        # iが奇数の時＝うるう
        if not i % 2:
            uru |= koho & baisu
        koho -= baisu
    if not n % 2:
        uru |= koho
    print(len(uru))

