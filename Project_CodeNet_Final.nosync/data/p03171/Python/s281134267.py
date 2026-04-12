from numpy import*
n,a=open(0)
n=int(n)
a=int64(a.split())
dp=zeros((n+1,n+1),'i8')
for k in range(1,n+1):
    i=arange(n-k+1)
    j=i+k
    dp[i,j]=amin(vstack((dp[i+1,j]-a[i],dp[i,j-1]-a[j-1])),0)if(n-k)%2else amax(vstack((dp[i+1,j]+a[i],dp[i,j-1]+a[j-1])),0)
print(dp[0,n])