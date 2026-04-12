A,B,C,X,Y=list(map(int,input().split()))
ans=0
if (A+B)/2>=C:
    ans+=2*C*min(X,Y)
else:
    ans+=(A+B)*min(X,Y)

if X>=Y and A>=2*C:
    ans+=2*C*abs(X-Y)
elif X>=Y:
    ans+=A*abs(X-Y)
elif X<Y and B>=2*C:
    ans+=2*C*abs(X-Y)
else:
    ans+=B*abs(X-Y)
print(ans)
