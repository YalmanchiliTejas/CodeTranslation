n=int(input())
s=list(map(int ,input().split()))

sum=[0]*n

sum[-1]=s[-1]

for i in range(n-2,-1,-1):
    sum[i]=sum[i+1]+s[i]

ans=0
for i in range(n-1):
    ans=ans+sum[i+1]*s[i]

print(ans%(1000000007))
