from itertools import accumulate
def main():
    n=int(input())
    a=list(map(int,input().split()))
    aa=list(accumulate(a))
    mod=10**9+7
    ans=0
    for i in range(n):
        ans += a[i]*(aa[-1]-aa[i])%mod
    print(ans%mod)
    
if __name__ == "__main__":
    main()