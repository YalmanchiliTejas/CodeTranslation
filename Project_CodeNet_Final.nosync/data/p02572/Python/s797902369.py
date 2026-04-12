MOD = pow(10, 9) + 7
waru2 = pow(2, MOD-2, MOD)

def main():
    N = int(input())
    A = list(map(int, input().split()))
    taikaku = 0
    for i in range(N):
        taikaku += pow(A[i], 2)
        taikaku %= MOD
    zennbu = 0
    sumA = sum(A)
    for i in range(N):
        zennbu += A[i]*sumA
        zennbu %= MOD
    
    ans = ((zennbu - taikaku) * waru2) % MOD
    print(ans)

if __name__ == "__main__":
    main()
