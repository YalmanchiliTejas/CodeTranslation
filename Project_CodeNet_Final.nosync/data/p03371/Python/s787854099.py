a,b,c,x,y=map(int,input().split())
ans1=x*a+y*b
if x>=y:
    ans2=2*y*c+(x-y)*a#(x,y)=(3,2)であればABを4枚買う
else:
    ans2=2*x*c+(y-x)*b
ans3=2*max(x,y)*c
print(min(ans1,ans2,ans3))