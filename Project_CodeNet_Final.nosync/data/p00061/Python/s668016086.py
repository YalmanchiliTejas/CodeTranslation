po = []
t2p = {}
while True:
    t, p = list(map(int, input().strip().split(',')))
    if t==0 and p==0:
        break
    t2p[t] = p
    po.append(p)

ps = sorted(list(set(po)),reverse=True)
while True:
    try:
        q = int(input().strip())
        r = 1
        for i in ps:
            if t2p[q] < i:
                r += 1
            else:
                break
        print(r)

    except EOFError:
        break