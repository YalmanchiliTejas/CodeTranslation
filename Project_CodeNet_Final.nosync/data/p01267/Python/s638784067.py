for e in iter(input, '0 0 0 0 0'):
    N, A, B, C, X = map(int, e.split())
    Y = [*map(int, input().split())]
    lenY = len(Y)
    tgt = Y[0] == X
    cnt = 0
    while tgt < lenY and cnt < 10000:
        cnt += 1
        X = (A * X + B) % C
        tgt += Y[tgt] == X
    print(cnt if tgt == lenY else -1)
