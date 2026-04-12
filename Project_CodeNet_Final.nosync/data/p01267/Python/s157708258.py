while True:
    N, A, B, C, X = map(int, raw_input().split())

    if N == 0 and A == 0 and B == 0 and C == 0 and X == 0:
        break

    Y = map(int, raw_input().split())

    ans, i = 0, 0

    while True:
        if X == Y[i]:
            i += 1

        if i == N:
            break

        X = (A*X + B) % C

        ans += 1
        if ans > 10000:
            ans = -1
            break

    print ans

