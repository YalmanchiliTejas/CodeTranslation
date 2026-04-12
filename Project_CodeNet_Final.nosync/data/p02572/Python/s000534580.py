import sys

sys.setrecursionlimit(10 ** 8)

input = sys.stdin.readline


def main():
    N = int(input())
    A = [int(x) for x in input().split()]

    MOD = 10 ** 9 + 7

    ruiseki = [0] * N

    for i in range(N):
        ruiseki[i] = ruiseki[i - 1] + A[i]

    ans = 0
    s = sum(A)
    for i in range(N):
        ans += A[i] * (s - ruiseki[i])
        ans %= MOD

    print(ans)

    

if __name__ == '__main__':
    main()

