def solve():
    N = int(input())

    # print(N)

    return 800 * N - (N // 15 * 200)


if __name__ == '__main__':
    res = solve()
    print(res)
