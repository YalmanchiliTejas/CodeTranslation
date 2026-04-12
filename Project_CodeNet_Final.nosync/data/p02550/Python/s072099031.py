def solve(N, X, M):
    x = X
    table = [-1] * M
    a = []
    length = 0
    # ループするまで配列に値を入れていく
    while table[x] == -1:
        a.append(x)
        table[x] = length
        length += 1
        x = x**2 % M

    # ループの開始位置とループの合計値を求める
    start = table[x]
    loop_total = 0
    for i in range(table[x], length):
        loop_total += a[i]

    # 答えの計算
    ans = 0
    if N <= length:
        for i in range(N):
            ans += a[i]
    else:
        # フルで何周するかを計算
        count = N - start
        count //= (length-start)
        ans += count * loop_total
        count *= (length-start)
        count = N - count
        for i in range(count):
            ans += a[i]

    return ans


if __name__ == "__main__":
    N, X, M = map(int, input().split())
    print(solve(N, X, M))
