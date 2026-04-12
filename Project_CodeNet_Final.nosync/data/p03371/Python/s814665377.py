a,b,c,x,y=map(int,input().split())
ans=0
if a+b>=2*c:
    if x>=y:
        ans+=2*c*y
        x-=y
        y-=y
        if a<2*c:
            ans+=a*x
        else:
            ans+=2*c*x
    else:
        ans+=2*c*x
        y-=x
        x-=x
        #print(ans)
        if b<2*c:
            ans+=b*y
        else:
            #print("ok")
            ans+=2*c*y
else:
    ans+=(a*x+b*y)
print(ans)