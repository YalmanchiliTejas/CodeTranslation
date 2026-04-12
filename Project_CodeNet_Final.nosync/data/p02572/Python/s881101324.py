def main():
    MOD = 10**9 + 7
    n = int(input())
    a = list(map(int, input().split()))
    a_sum = sum(a)
    ans = 0
    
    for i in range(n):
        ans += a[i] * (a_sum - a[i])
    print(ans // 2 % MOD)
        
        
if __name__ == '__main__':
    main()