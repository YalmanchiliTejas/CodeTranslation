import sys

read = sys.stdin.buffer.read
readline = sys.stdin.buffer.readline
readlines = sys.stdin.buffer.readlines

in_n = lambda: int(readline())
in_nn = lambda: map(int, readline().split())
in_s = lambda: readline().rstrip().decode('utf-8')
in_nl = lambda: list(map(int, readline().split()))
in_nl2 = lambda H: [in_nl() for _ in range(H)]
in_map = lambda: [s == ord('.') for s in readline() if s != ord('\n')]
in_map2 = lambda H: [in_map() for _ in range(H)]
in_all = lambda: map(int, read().split())


def main():

    N = in_n()
    A = in_nl()

    ans = 0
    mod = 10**9 + 7
    sum_a = sum(A)
    tsum = [0] * (N + 1)

    for i in range(N):
        tsum[i + 1] = tsum[i] + A[i]

    for i in range(N):
        ans += A[i] * (sum_a - tsum[i + 1])
        ans %= mod

    print(ans)


if __name__ == '__main__':
    main()
