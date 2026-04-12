def resolve():
    N = int(input())
    A = list(map(int, input().split()))
    x = [0] * N
    tot = 0
    for i in range(N-1, 0, -1):
        tot += A[i]
        x[i] = tot

    ans = 0
    for i in range(N-1):
        ans += A[i] * x[i+1]
    ans = ans % (10**9 + 7)
    print(ans)

if __name__ == "__main__":
    resolve()