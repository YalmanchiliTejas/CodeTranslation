n=int(input())
a=[0]*n
for  i in range(n):
    a[i]=int(input())
a.sort(reverse=True)
ans=0
aupper=a[:n//2]
adowner=a[n//2:]
if len(a)==2:print(a[0]-a[1])
elif len(a)==3:
    print(max(sum(a[:n-1])-a[n-1]*2,a[0]*2-sum(a[1:])))
elif n%2==1:
    ans1=0;ans2=0
    for i in range(n//2):
        ans1+=aupper[i]*2-(adowner[i]+adowner[i+1])
    ans1+=(adowner[1]-adowner[-1])
    a=a[::-1]
    adowner=a[:n//2]
    aupper=a[n//2:]
    for i in range(n//2):
        ans2+=aupper[i]+aupper[i+1]-adowner[i]*2
    ans2+=aupper[-1]-aupper[1]
    print(max(ans1,ans2))
else:
    ans=0
    for i in range(n//2):
        if i!=n//2-1:
            ans+=aupper[i]*2-(adowner[i]+adowner[i+1])
        else:
            ans+=aupper[i]-adowner[i]
    print(ans)