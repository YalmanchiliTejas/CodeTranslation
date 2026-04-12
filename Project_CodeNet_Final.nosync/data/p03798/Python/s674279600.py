import sys

sys.setrecursionlimit(10 ** 6)
INF = float("inf")
MOD = 10 ** 9 + 7


def input():
    return sys.stdin.readline().strip()


def main():
    N = int(input())
    S = input()

    # 0番目と1番目を決めれば他が全部決まる
    for s0, s1 in [("S", "W"), ("W", "S"), ("S", "S"), ("W", "W")]:
        ans = [None] * N
        ans[0] = s0
        ans[1] = s1
        for i in range(1, N - 1):
            if ans[i] == "S":
                s = S[i]
            else:
                if S[i] == "o":
                    s = "x"
                else:
                    s = "o"

            if s == "o":
                ans[i + 1] = ans[i - 1]
            else:
                if ans[i - 1] == "S":
                    ans[i + 1] = "W"
                else:
                    ans[i + 1] = "S"

        if ans[-1] == "S":
            if S[-1] == "o":
                if ans[-2] == ans[0]:
                    pass
                else:
                    continue
            else:
                if ans[-2] != ans[0]:
                    pass
                else:
                    continue
        else:
            if S[-1] == "o":
                if ans[-2] != ans[0]:
                    pass
                else:
                    continue
            else:
                if ans[-2] == ans[0]:
                    pass
                else:
                    continue

        if ans[0] == "S":
            if S[0] == "o":
                if ans[-1] == ans[1]:
                    print(*ans, sep="")
                    return
                else:
                    continue
            else:
                if ans[-1] != ans[1]:
                    print(*ans, sep="")
                    return
                else:
                    continue
        else:
            if S[0] == "o":
                if ans[-1] != ans[1]:
                    print(*ans, sep="")
                    return
                else:
                    continue
            else:
                if ans[-1] == ans[1]:
                    print(*ans, sep="")
                    return
                else:
                    continue

    else:
        print(-1)


if __name__ == "__main__":
    main()
