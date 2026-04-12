# coding: utf-8
# Your code here!
A,B,C,X,Y=map(int,input().split())

ooiXY=max(X,Y)
sukunaiXY=min(X,Y)
ans1=C*ooiXY*2
ans2=A*X+B*Y
ans3=C*sukunaiXY*2+A*(X-sukunaiXY)+B*(Y-sukunaiXY)

print(min(ans1,ans2,ans3))