# 約分してから計算するアルゴリズム

def combination(n, r):
    # n >= 0, r >= 0, r <= n を仮定
    if n < 0 or r < 0 or n < r:
        return 0

    # r <= n - r を仮定
    if n - r < r:
        r = n - r

    # r < 2 の場合
    if r == 0:
        return 1
    if r == 1:
        return n

    # nCr の分子
    # [n - r + 1, n - r + 2, ... , n - 1, n]
    numerator = [n - r + 1 + i for i in range(r)]


    # nCr の分母
    # [1, 2, ... , r - 1, r]
    denominator = [i + 1 for i in range(r)]

    # nCr を約分する
    for i in range(r):
        # i番目の分母で約分する
        # 0番目は1なので省略

        # 元の（今までの約分を行う前の）i番目の分母の値
        original_denominator = i + 1

        # 今までの約分を行った後の、i番目の分母の値
        # 今回の約分で割る数
        divisor = denominator[i]

        # divisorが1（全て約分済み）の場合は無視する
        if divisor == 1:
            continue

        # 約分する相手の分子を決める
        # 0～i番目の分子（約分前）の中で、
        # original_denominatorで割り切れる数
        # （一つしかない）を選ぶ
        # remainder = i番目の分子 % original_denominator
        # とするとき、
        # (i - remainder)番目の分子 = i番目の分子 - remainder
        # (i - remainder)番目の分子 % original_denominator
        #  = (i番目の分子 - remainder) % original_denominator
        #  = 0
        # なので、(i - remainder)番目の分子を選べばよい。

        # remainder = i番目の分子 % original_denominator
        #           = (n - r + i + 1) % (i + 1)
        #           = (n - r) % (i + 1)
        remainder = (n - r) % original_denominator

        # divisor で約分できるペアをすべて約分する
        for j in range(i, r, original_denominator):
            numerator[j - remainder] = numerator[j - remainder] // divisor
            denominator[j] = denominator[j] // divisor

    ans = 1
    for i in numerator:
        ans *= i
    return ans


N_string = input()
N = int(N_string)
K = int(input())

if N < 10:
    if K == 1:
        print(N)
    else:
        print(0)
# elif N < 100:
#     if K == 1:
#         print(9 + N // 10)
#     elif K == 2:
#         print(9 * (N // 10 - 1) + (N - (N // 10) * 10))
#     else:
#         print(0)
else:
    # 10 ** n <= N < 10 ** (n + 1) なる n
    # すなわち、N が n + 1 桁であるような n
    n = len(N_string) - 1

    # 10 ** n 未満で条件を満たす整数の数
    ans = combination(n, K) * (9 ** K)

    # Nの先頭の数字
    a = int(N_string[0])

    if K == 1:
        ans += a
    else:
        # a以外に0でない数字が出現するかどうか
        if N_string[1:] == "0" * n:
            # 出現しないとき
            ans += (a - 1) * combination(n, K - 1) * (9 ** (K - 1))
        else:
            # 出現するとき
            # Nの2番目の0以外の数字とその表れる桁数を計算
            m = n - 1
            while True:
                if N_string[n - m] != "0":
                    b = int(N_string[n - m])
                    break
                m -= 1

            if K == 2:
                # n + 1 桁かつ、先頭の数字が1以上a未満であるような、
                # 問題の条件を満たす整数の個数
                ans += (a - 1) * combination(n, K - 1) * 9

                # n + 1 桁かつ、先頭の数字が　a　であるような、
                # 問題の条件を満たす整数でN以下のもののの個数
                ans += combination(m, 1) * 9 + b
            else:
                # K == 3
                # a, b以外に0でない数字が出現するかどうか
                if N_string[n - m + 1:] == "0" * m:
                    # 出現しないとき

                    # n + 1 桁かつ、先頭の数字が1以上a未満であるような、
                    # 問題の条件を満たす整数の個数
                    ans += (a - 1) * combination(n, 2) * 9 * 9

                    # n + 1 桁で先頭の数字が　a　かつ、 m + 1 桁目が0であるような、
                    # 問題の条件を満たす整数でN以下のもののの個数
                    ans += combination(m, 2) * 9 * 9

                    # n + 1 桁で先頭の数字が a かつ、
                    # m + 1 桁目の数字が1以上b未満であるような、
                    # 問題の条件を満たす整数の個数
                    ans += (b - 1) * combination(m, 1) * 9
                else:
                    # Nの3番目の0以外の数字とその表れる桁数を計算
                    l = m - 1
                    while True:
                        if N_string[n - l] != "0":
                            c = int(N_string[n - l])
                            break
                        l -= 1

                    # n + 1 桁かつ、先頭の数字が1以上a未満であるような、
                    # 問題の条件を満たす整数の個数
                    ans += (a - 1) * combination(n, K - 1) * 9 * 9

                    # n + 1 桁で先頭の数字が　a　かつ、 m + 1 桁目が0であるような、
                    # 問題の条件を満たす整数でN以下のもののの個数
                    ans += combination(m, K - 1) * 9 * 9

                    # n + 1 桁で先頭の数字が a かつ、
                    # m + 1 桁目の数字が1以上b未満であるような、
                    # 問題の条件を満たす整数の個数
                    ans += (b - 1) * combination(m, K - 2) * 9

                    # n + 1 桁で先頭の数字が a かつ、
                    # m + 1 桁目の数字が　b　であるような、
                    # 問題の条件を満たす整数でN以下のもののの個数
                    ans += combination(l, 1) * 9 + c

    print(ans)
