a,b,ab,x,y=map(int,input().split())
ans=0
if ab<(a+b)/2:
    m=min(x,y)
    ans+=ab*2*m
    x-=m
    y-=m
    if x==y==0:
        print(ans)
        exit()
    if y==0:
        if ab*2<a:
            ans+=x*2*ab
        else:
            ans+=x*a
    else:
        if ab*2<b:
            ans+=y*2*ab
        else:
            ans+=y*b

else:
    ans+=x*a+y*b

print(ans)