def main():
    n, x, m = map(int, input().split())

    idx = [-1] * m

    i = 1
    y = x
    while not(~idx[y]):
        idx[y] = i
        y = (y * y) % m
        i += 1
    start = idx[y]
    end = i

    loop_len = end - start  # [start,end)

    ans = 0
    rep = 0

    rep_flg = False
    finish = False

    j = 1
    while j <= n:
        if finish:
            ans += x
        else:
            if j == start or j == end:
                if rep_flg:
                    k = (n - 1 - j) // loop_len
                    ans += (k + 1) * rep
                    j += k * loop_len
                    rep_flg = False
                    finish = True
                    if j == n:
                        break
                else:
                    rep_flg = True
            if rep_flg:
                rep += x
            else:
                ans += x
        x = (x * x) % m
        j += 1

    if not finish:
        ans += rep
    print(ans)


if __name__ == '__main__':
    main()
