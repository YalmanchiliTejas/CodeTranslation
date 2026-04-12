
def solve():
    N, X, M = map(int, input().split())

    _l = tuple([i**2 % M for i in range(M)])

    _a = X
    ans_l = [0] * M
    ans_l[0] = _a
    seq = [_a]
    s = g = 0
    for i in range(1, M):
        _a = _l[_a]
        ans_l[i] = _a + ans_l[i-1]
        if _a in seq:
            s = seq.index(_a)
            g = len(seq)-1
            break
        seq.append(_a)
    _tmp = N - s
    loop = _tmp // (g - s + 1)
    zan = _tmp % (g - s + 1)
    ans = ans_l[s-1] + (ans_l[g] - ans_l[s-1]) * loop + \
        (ans_l[s+zan-1] - ans_l[s-1])
    print(ans)


solve()
