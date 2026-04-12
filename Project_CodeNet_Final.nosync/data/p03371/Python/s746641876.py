A,B,C,X,Y = map(int,input().split())

if A+B<2*C:
    tmp=A+B
else:
    tmp=2*C

ans=tmp*min(X,Y)

#print(ans)

X2=X-min(X,Y)
Y2=Y-min(X,Y)

a1=X2*A+Y2*B
a2=X2*2*C+Y2*2*C

if a1<a2:
    print(ans+a1)
else:
    print(ans+a2)