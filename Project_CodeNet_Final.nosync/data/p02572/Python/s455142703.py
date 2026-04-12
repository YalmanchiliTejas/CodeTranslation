def main():
    import sys
    sys.setrecursionlimit(10**6)
    input = sys.stdin.readline
    N = int(input())
    A = [int(x) for x in input().strip().split()]
    MOD = 10 ** 9 + 7
    sumA = sum(A)
    ans = 0
    for n in range(N-1):
        sumA -= A[n]
        ans += sumA * A[n]
        ans %= MOD
    print(ans)

if __name__ == '__main__':
    main()