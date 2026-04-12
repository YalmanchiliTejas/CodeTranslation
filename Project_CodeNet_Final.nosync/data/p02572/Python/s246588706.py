mod = 1000000007

def solve():
    N = int(input())
    A = [int(i) for i in input().split()]
    ans = 0
    s = sum(A)
    for i in range(N - 1):
        s -= A[i]
        ans += A[i] * s
    print(ans % mod)

if __name__ == "__main__":
    solve()