import sys
sys.setrecursionlimit(10**6)

MOD = 10**9+7


def main(input, print):
    N = int(input())
    A = list(map(int, input().split()))

    ans = 0
    t = 0
    for i in reversed(range(N-1)):
        t += A[i+1]
        t %= MOD
        ans += t * A[i]
        ans %= MOD
    print(ans)


if __name__ == '__main__':
    main(sys.stdin.readline, print)
