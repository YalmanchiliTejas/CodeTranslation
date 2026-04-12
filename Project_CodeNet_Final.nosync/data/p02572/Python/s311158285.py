def main():
    N = int(input())
    A = [int(c) for c in input().split() if int(c) > 0]
    MOD = int(10**9+7)
 
    mono = 0
    bi = 0
    for x in A:
        mono += x
        #mono %= MOD
        bi += x**2
        #bi %= MOD
    ans = (mono**2 - bi)//2
    ans %= MOD
    print(ans)
 
if __name__ == '__main__':
    main()