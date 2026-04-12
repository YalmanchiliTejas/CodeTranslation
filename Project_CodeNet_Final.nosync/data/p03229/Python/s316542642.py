import sys
N=int(input())
a=[]

for i in range(N):
    a.append(int(input()))

a.sort()
ans=0
ans2=0
if N%2==0:
    ans=2*sum(a[N//2:N])-a[N//2]-2*sum(a[0:N//2])+a[N//2-1]
    print(ans)
else:
    ans=2*sum(a[N//2+1:N])-2*sum(a[0:N//2+1])+a[N//2]+a[N//2-1]
    ans2=2*sum(a[N//2:N])-a[N//2]-a[N//2+1]-2*sum(a[0:N//2])
    print(max(ans,ans2))