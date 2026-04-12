def main():
    N = int(input())
    A = [int(input()) for _ in range(N)]
    A.sort()
    # (1) N = 2n + 1
    #     (1-1): p1 >= p2 <= p3 >= ... <= pN
    #         各pの隣同士の差の和における係数について考えると
    #         2: n-1個（両端以外の山）、1: 2個（両端）、-2: n個（谷）。
    #     (1-2): p1 <= p2 >= p3 <= ... >= pN
    #         各pの隣同士の差の和における係数について考えると
    #         2: n個（山）、-1: 2個（両端）、-2: n-1個（両端以外の谷）。
    if N % 2 == 1:
        n = N // 2
        ans_1 = 0
        for i, a in enumerate(A):
            coef = 2
            if i < n:  # 小さい順で1～n番目は係数-2
                coef = -2
            elif i < n + 2:  # 小さい順でn+1～n+2番目は係数1
                coef = 1
            ans_1 += coef * a
        ans_2 = 0
        for i, a in enumerate(A):
            coef = 2
            if i < n - 1:  # 小さい順で1～n-1番目は係数-2
                coef = -2
            elif i < n + 1:  # 小さい順でn～n+1番目は係数1
                coef = -1
            ans_2 += coef * a
        print(max(ans_1, ans_2))
    # (2) N = 2n
    #     p1 >= p2 <= p3 >= ... >= pN
    #     各pの隣同士の差の和における係数について考えると
    #     2: n-1個（左端以外の山）、1: 1個（左端）、-1: 1個（右端）、-2: n-1個（谷）。
    else:
        n = N // 2
        ans = 0
        for i, a in enumerate(A):
            coef = 2
            if i < n - 1:  # 小さい順で1～n-1番目は係数-2
                coef = -2
            elif i < n:  # 小さい順でn番目は係数-1
                coef = -1
            elif i < n + 1:  # 小さい順でn+1番目は係数1
                coef = 1
            ans += coef * a
        print(ans)


if __name__ == '__main__':
    main()