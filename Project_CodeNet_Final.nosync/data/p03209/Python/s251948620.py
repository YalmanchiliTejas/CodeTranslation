# B-R()-P-R()-B

N, X = map(int, input().split())

total = [1] + [0] * N
psum = [1] + [0] * N
for i in range(1, N + 1):
    total[i] = total[i - 1] * 2 + 3
    psum[i] = psum[i - 1] * 2 + 1

# layer k, rest x
def f(k, x):
    if x == 0:
        return 0
    if k == 0:
        assert x == 1
        return 1

    ret = 0

    # 一番左の B を食べる
    if x <= 1:
        return ret
    x -= 1

    # L-1 を食べる
    # 枚数は分かっている (total, psum) ので全部食べられるならそれを使って終わり
    # 切れ目が途中にある場合は再帰呼び出し
    if x <= total[k - 1]:
        return ret + f(k - 1, x)
    ret += psum[k - 1]
    x -= total[k - 1]

    # 真ん中の P を食べる
    if x < 1:
        return ret
    ret += 1
    x -= 1

    # 2回目の L-1 を食べる
    if x <= total[k - 1]:
        return ret + f(k - 1, x)
    ret += psum[k - 1]
    x -= total[k - 1]

    # 最後の B を食べる (残り 0 or 1 でないと何かがおかしい)
    assert x <= 1
    return ret

print(f(N, X))
