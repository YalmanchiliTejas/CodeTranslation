from itertools import accumulate
def main():
    mod=10**9+7
    n=int(input())
    a=list(map(int,input().split()))
    aa=[0]+list(accumulate(a))
    ans=0
    for i in range(n-1):
        ans += a[i]*(aa[-1]-aa[i+1])%mod
    print(ans%mod)

if __name__ == '__main__':
    main()