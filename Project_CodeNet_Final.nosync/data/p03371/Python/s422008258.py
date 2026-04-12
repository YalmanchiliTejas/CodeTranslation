A,B,C,X,Y=map(int,input().split())
m=min(X,Y)
d=A+B
c=2*C
ans=0
if d>c:
    ans+=c*m
else:
    ans+=d*m
l=max(X,Y)
if X>Y:
    if A>c:
        ans+=c*(l-m)
    else:
        ans+=A*(l-m)
else:
    if B>c:
        ans+=c*(l-m)
    else:
        ans+=B*(l-m)
print(ans)