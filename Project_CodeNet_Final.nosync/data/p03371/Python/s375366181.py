# coding: utf-8
a,b,ab,x,y=map(int,input().split())
ans=0
if a+b>ab*2:
    mn=min(x,y)
    ans+=ab*2*mn
    x-=mn
    y-=mn
if a>ab*2:
    ans+=x*ab*2
    y-=x
else:
    ans+=x*a
if y>0:
    if b>ab*2:
        ans+=y*ab*2
    else:
        ans+=y*b
print(ans)