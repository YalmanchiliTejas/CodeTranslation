n=int(input())
l=[]
for i in range(n):
    l.append(int(input()))
l.sort()
if n%2==0:
    s=l[:n//2]
    b=l[n//2:]
    ans=0
    for i in range(n-1):
        if i%2==0:
            ans+=b[i//2]-s[i//2]
        else:
            ans+=b[(i+1)//2]-s[i//2]
    print(ans)
else:
    s=l[:n//2]
    b=l[n//2+1:]+[l[n//2]]
    ans1=0
    for i in range(n-1):
        if i%2==0:
            ans1+=b[i//2]-s[i//2]
        else:
            ans1+=b[(i+1)//2]-s[i//2]
    t=[l[(n//2)]]+l[:n//2]
    c=l[n//2+1:]
    ans2=0
    for i in range(n-1):
        if i%2==0:
            ans2+=c[i//2]-t[i//2]
        else:
            ans2+=c[i//2]-t[(i+1)//2]
    print(max(ans1,ans2))