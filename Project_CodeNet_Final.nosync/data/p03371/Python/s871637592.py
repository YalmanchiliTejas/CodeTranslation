a,b,c,X,Y=map(int,input().split())

s=min(X,Y)
t=max(X,Y)

ans1=2*c*s+a*(X-s)+b*(Y-s)
ans2=a*X+b*Y
ans3=2*c*t

print(min(ans1,ans2,ans3))

  