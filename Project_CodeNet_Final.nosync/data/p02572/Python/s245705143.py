def main():
    mod = 10**9+7
    #n,a = get_input()
    n = int(input())
    a = [int(x) for x in input().split()]
    ans = 0
    asum = sum(a) 
    for i in range(n):
        asum = asum - a[i]
        ans = ( ans + ((a[i] * asum) % mod)) % mod
    
    print(ans)
    
if __name__ == '__main__':
    main()