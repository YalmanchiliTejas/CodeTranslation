MOD = int(1e9+7)


def main():
    n = int(input())    
    A = list(map(int,input().split()))
    sum_a = 0
    for a in A:
        sum_a = (sum_a + a) % MOD
        
    ans = 0
    for a in A:
        sum_a = (sum_a - a) % MOD
        ans = (ans + ((a*sum_a) % MOD)) % MOD
    print(ans)


if __name__ == "__main__":
    main()