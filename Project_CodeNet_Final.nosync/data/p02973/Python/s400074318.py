from bisect import *


def p_e():
    N = int(input())
    # A = [int(input()) for _ in range(N)]
    ans = [-1] * N

    for _ in range(N):
        a = int(input())
        ans[bisect(ans, a - 1) - 1] = a

    print(N - bisect(ans, -1))


if __name__ == '__main__':
    p_e()
