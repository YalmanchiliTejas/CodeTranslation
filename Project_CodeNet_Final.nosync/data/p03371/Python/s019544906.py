A,B,C,X,Y=map(int,input().split())

ans=10**9

my_min=min(X,Y)
my_max=max(X,Y)

ans1=2*C*my_min+A*(X-my_min)+B*(Y-my_min)
ans2=2*C*my_max
ans3=A*X+B*Y
print(min(ans1,ans2,ans3))