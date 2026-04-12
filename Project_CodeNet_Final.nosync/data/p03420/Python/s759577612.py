def main():
    N, K = map(int, input().split())

    if K == 0:
        print(N ** 2)
        return

    ans = 0
    for b in range(K + 1, N + 1):
        q, r = divmod(N, b)
        ans += q * (b - K) + max(0, r - (K - 1))
    print(ans)


if __name__ == '__main__':
    main()

# import sys
#
# sys.setrecursionlimit(10 ** 7)
#
# input = sys.stdin.readline
# rstrip()
# int(input())
# map(int, input().split())

# a % b >= K
