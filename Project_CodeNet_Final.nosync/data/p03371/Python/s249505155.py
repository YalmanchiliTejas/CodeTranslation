A,B,C,X,Y= map(int, input().split())
ans=0
ans=A*X+B*Y

z=min(X,Y)
x=X-z
y=Y-z
ans=min(ans,x*A+y*B+C*2*z)

z=max(X,Y)
ans=min(ans,C*2*z)
print(ans)