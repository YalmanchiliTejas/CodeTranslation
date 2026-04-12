U, F, R, L, B, D = range(6)
while True:
    n = int(input())
    if n == 0:
        break
    s = list(range(1, 6 + 1))
    result = 1
    for _ in range(n):
        raw = input()
        assert raw.find('\t') == -1
        op = raw.strip()
        if op == "North":
            s[U], s[F], s[D], s[B] = s[F], s[D], s[B], s[U]
        elif op == "South":
            s[U], s[F], s[D], s[B] = s[B], s[U], s[F], s[D]
        elif op == "West":
            s[U], s[R], s[D], s[L] = s[R], s[D], s[L], s[U]
        elif op == "East":
            s[U], s[R], s[D], s[L] = s[L], s[U], s[R], s[D]
        elif op == "Right":
            s[F], s[R], s[B], s[L] = s[R], s[B], s[L], s[F]
        elif op == "Left":
            s[F], s[R], s[B], s[L] = s[L], s[F], s[R], s[B]
        else:
            assert False
        result += s[U]
    print(result)
