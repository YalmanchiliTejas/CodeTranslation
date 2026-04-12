import sys
from itertools import accumulate

read = sys.stdin.read
readline = sys.stdin.buffer.readline
sys.setrecursionlimit(10 ** 8)
INF = float('inf')
MOD = 10 ** 9 + 7


def main():
    N = int(readline())
    A = list(map(int, readline().split()))
    Acum = list(accumulate(A))
    ans = 0
    for i in range(N-1):
        ans += A[i] * (Acum[N-1] - Acum[i]) %MOD
        ans %= MOD
    print(ans)



if __name__ == '__main__':
    main()
