import sys

read = sys.stdin.buffer.read
readline = sys.stdin.buffer.readline

in_n = lambda: int(readline())
in_nn = lambda: map(int, readline().split())
in_nl = lambda: list(map(int, readline().split()))
in_na = lambda: map(int, read().split())
in_s = lambda: readline().rstrip().decode('utf-8')


def main():
    N, K = in_nn()

    ans = 0
    for b in range(K + 1, N + 1):
        q, r = divmod(N, b)
        ans += q * (b - K) + max(0, r - K + 1)
        if K == 0:
            ans -= 1

    print(ans)


if __name__ == '__main__':
    main()
