import bisect


def main():
    INF = 10 ** 10
    N = int(input())
    A = [int(input()) for _ in range(N)]
    A.reverse()
    B = [INF for _ in range(N)]
    for a in A:
        index = bisect.bisect_right(B, a)
        B[index] = a
    ans = 0
    for b in B:
        if b == INF:
            break
        ans += 1
    print(ans)


if __name__ == '__main__':
    main()