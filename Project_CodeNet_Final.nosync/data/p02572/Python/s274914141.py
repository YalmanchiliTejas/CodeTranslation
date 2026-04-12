def main():
    n=int(input())
    a=list(map(int, input().split()))
    mod=10**9+7
    ans=((sum(a)%mod)**2)%mod
    for i in range(n):
      ans-=a[i]**2
      ans%=mod
    m=pow(2,mod-2,mod)
    print(ans*m%mod)   
main()