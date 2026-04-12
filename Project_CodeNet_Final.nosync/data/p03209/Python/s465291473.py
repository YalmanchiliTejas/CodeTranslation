def main():
    from functools import lru_cache
    import sys

    sys.setrecursionlimit(10 ** 7)

    N, X = map(int, input().split())

    size = [0] * (N + 1)
    patty = [0] * (N + 1)
    size[0] = 1
    patty[0] = 1
    for lv in range(1, N + 1):
        size[lv] = size[lv - 1] * 2 + 3
        patty[lv] = patty[lv - 1] * 2 + 1

    @lru_cache(maxsize=None)
    def burger(lv, x):
        if lv == 0:
            return int(x > 0)

        if x <= 1:
            return 0

        if x <= 1 + size[lv - 1]:
            return burger(lv - 1, x - 1)

        if x == 1 + size[lv - 1] + 1:
            return patty[lv - 1] + 1

        if x <= 1 + size[lv - 1] + 1 + size[lv - 1]:
            return patty[lv - 1] + 1 + burger(lv - 1, x - (1 + size[lv - 1] + 1))

        return patty[lv]

    ans = burger(N, X)
    print(ans)


if __name__ == '__main__':
    main()
