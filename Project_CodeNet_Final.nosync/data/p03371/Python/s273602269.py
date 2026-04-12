a,b,c,x,y=map(int,input().split())

#全てABピザ
ans1=max(x,y)*2*c
#AはABピザ　BはBピザ
ans2=x*2*c+max(y-x,0)*b
#BはABピザ　AはAピザ
ans3=y*2*c+max(x-y,0)*a
#全てAピザBピザ
ans4=a*x+b*y
print(min(ans1,ans2,ans3,ans4))