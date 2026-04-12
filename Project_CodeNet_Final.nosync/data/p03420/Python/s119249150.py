import sys

read = sys.stdin.read
readline = sys.stdin.buffer.readline
sys.setrecursionlimit(10 ** 8)
INF = float('inf')
MOD = 10 ** 9 + 7


def main():
    N, K = map(int, readline().split())
    ans = 0
    for i in range(K + 1, N + 1):
        ans += N // i * (i - K)
        if N % i > 0:
            if K == 0:
                ans += N % i
            else:
                ans += max(0, N % i - K + 1)
    print(ans)
if __name__ == '__main__':
    main()
