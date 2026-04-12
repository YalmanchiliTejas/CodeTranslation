import sys

MOD = 10**9 + 7

def main():
    N = int(sys.stdin.readline().rstrip())
    A = [int(x) for x in sys.stdin.readline().rstrip().split()]

    Asum = sum(A)
    ans = 0
    for i in range(N-1):
        Asum -= A[i]
        Asum %= MOD
        ans += A[i] * Asum
        ans %= MOD
    
    print(ans)


main()