if __name__ == "__main__":
    N = int(input())
    A = list(map(int, input().split()))
    R = [0]
    MOD = 10**9 + 7
    ans = 0
    for i in range(N):
        R.append(A[i]+R[-1])
    for i in range(N-1):
        ans += A[i] * (R[-1] - R[i+1])
        ans %= MOD
    print(ans)
