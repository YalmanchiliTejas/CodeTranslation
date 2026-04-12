n=int(input())
a=[]
for i in range(n):
    a.append(int(input()))
a.sort(reverse=True)
ans=0
ans1=0
ans2=0
if n%2==0:
    for i in range(n//2):
        if i==n//2-1:
            ans+=a[i]
        else:
            ans+=2*a[i]
    for i in range(n-1,n//2-1,-1):
        if i==n//2:
            ans-=a[i]
        else:
            ans-=2*a[i]
else:
    for i in range((n+1)//2):
        if (i==(n-3)//2)|(i==(n-1)//2):
            ans1+=a[i]
        else:
            ans1+=2*a[i]
    for i in range((n+1)//2,n):
        ans1-=2*a[i]
    for i in range((n-1)//2):
        ans2+= 2 * a[i]
    for i in range((n-1)//2,n):
        if (i == (n-1)//2) | (i ==(n+1)//2):
            ans2-=a[i]
        else:
            ans2-=2 * a[i]
    ans=max(ans1,ans2)

print(ans)