mod = 10**9 + 7
N=int(input())
A = list(map(int,input().split()))
ans = sum(A)**2
for x in A:
    ans-=x**2
ans=ans//2
print(ans%mod)