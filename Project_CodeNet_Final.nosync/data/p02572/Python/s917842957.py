def main():
    N = int(input())
    A = list(map(int, input().split()))
    MOD = 10 ** 9 + 7

    b = A[0]
    ans = 0
    for i in range(1, N):
        ans = (ans + b * A[i]) % MOD
        b = (b + A[i]) % MOD
    
    print(ans)

if __name__ == '__main__':
    main()