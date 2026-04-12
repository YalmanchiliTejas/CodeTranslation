from itertools import accumulate

def main():
    N = int(input())
    A = list(map(int, input().split()))
    B = [0] + list(accumulate(A))
    MOD = 10 ** 9 + 7
    ans = 0
    for i in range(N):
        ans += A[i] * (B[N] - B[i+1])
        ans %= MOD

    print(ans)




if __name__ == "__main__":
    main()