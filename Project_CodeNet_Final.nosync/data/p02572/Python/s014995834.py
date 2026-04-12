N=int(input())
a=list(map(int,input().split()))
M=7+10**9
ans=0
s=0
for i in range(N-1):
    s+=a[i]
    ans+=s*a[i+1]
    ans%=M
print(ans)
