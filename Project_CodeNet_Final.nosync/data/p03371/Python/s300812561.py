a,b,c,x,y=map(int,input().split())

#全部ABピザで買う
ans1=c*max(x,y)*2

#AピザX個、BピザをY個、それぞれ買う
ans2=a*x+b*y

#X、Yの少ない方までABピザを買い、足りない分を買う
if(x<=y):
  ans3=c*x*2+(y-x)*b
else:
  ans3=c*y*2+(x-y)*a

print(min(ans1,ans2,ans3))
