def main():
    n, x, m = map(int, input().split())
    idx = [-1] * (m + 1)  # mで割った余り（0,1,...m-1）が何回目に出てきたか
    res = []  # 数列A

    for i in range(1, m + 3):  # 余りはm+1種類なのでm+2回計算すれば絶対ループが発生する
        if idx[x] == -1:  # 初めて
            idx[x] = i
            res.append(x)
            x = (x ** 2) % m
        else:  # 既出（ループ発見）
            len_loop = i - idx[x]
            len_head = idx[x] - 1
            break

    if n <= len_head + len_loop:  # 1ループ目までで出力する場合
        print(sum(res[:n]))
    else:
        ans = sum(res[:len_head])  # ループ前

        loop_count = (n - len_head) // len_loop
        ans += loop_count * sum(res[len_head:])  # ループ

        len_tail = (n - len_head) % len_loop
        ans += sum(res[len_head: len_head + len_tail])  # ループ後の余り

        print(ans)


if __name__ == "__main__":
    main()
