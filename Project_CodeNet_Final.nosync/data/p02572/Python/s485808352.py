import sys
import itertools

input = sys.stdin.readline


def main():
    N = int(input())
    A = list(map(int, input().split()))
    A = A[::-1]
    B = list(itertools.accumulate(A))
    MOD = 10**9+7
    ans = 0
    for i in range(N - 2, -1, -1):
        ans = (ans + A[i + 1] * B[i]) % MOD
    print(ans)


if __name__ == '__main__':
    main()
