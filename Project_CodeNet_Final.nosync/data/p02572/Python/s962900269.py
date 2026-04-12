def main():
    N = int(input())
    A = list(map(int,input().split()))
    ans = 0
    m0 = 10**9+7
    Ar = [0]*N
    sum0 = 0
    for i in reversed(range(N)):
        sum0 = (sum0 + A[i]) % m0
        Ar[i] = sum0

    for i in range(N-1):
        ans = (ans + A[i] * Ar[i+1]) % m0
    print(ans)

if __name__ == '__main__':
    main()