def main():
    mod = 10**9+7
    #n,a = get_input()
    n = int(input())
    a = [int(x) for x in input().split()]
    aa = [x**2 % mod for x in a]
    ans = 0
    asum = sum(a) 
    p = asum ** 2 % mod
    q = sum(aa) % mod
    ans = (p - q) % mod
    if ans < 0:
      ans += mod
    if ans % 2 == 1:
      ans += mod
    ans = ans // 2
    print(ans)
    
if __name__ == '__main__':
    main()