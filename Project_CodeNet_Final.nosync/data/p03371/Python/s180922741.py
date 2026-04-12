a,b,c,x,y=map(int,input().split())
num1=a*x+b*y
if x>y:
    num2=c*y*2+a*(x-y)
else:
    num2=c*x*2+b*(y-x)
num3=max(x,y)*c*2
print(min(num1,num2,num3))
