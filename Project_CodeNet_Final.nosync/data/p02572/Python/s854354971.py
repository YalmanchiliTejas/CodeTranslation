MOD = 10**9 + 7
N = int(input())
A = list(map(int, input().split()))


def main():
    SUM = []
    now = 0
    ans = 0
    for i in range(N):
        now += A[i]
        SUM.append(now)
    
    for i in range(N):
        ans += A[i] * (SUM[-1] - SUM[i])
        ans %= MOD

    print(ans)


if __name__ == "__main__":
    main()