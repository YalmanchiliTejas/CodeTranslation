if __name__ == '__main__':
    from collections import deque

    la = list(map(int, input().split()))

    nl = deque([])

    for i in range(0, la[0]):
        nl.append(list(input()))

    for j in range(len(nl)):
        if '#' not in nl[j]:
            nl[j].clear()

    sl = [u for u in nl if u]

    for c in range(0, la[1]):
        zl = [row[c] for row in sl]
        # print(zl)
        if '#' not in zl:
            for d in sl:
                d[c] = ''

    for e in range(len(sl)):
        sl[e] = [u for u in sl[e] if u]

    for k in sl:
        print(''.join(k))
