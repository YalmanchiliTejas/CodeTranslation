a,b,c,x,y=input().split()
a=int(a)
b=int(b)
c=int(c)
x=int(x)
y=int(y)
ans = 5000 * 100000 * 3 * 2
ans1 = a*x+b*y
ans2 = a*max(0,x-y)+c*2*y
ans3 = b*max(0,y-x)+c*2*x
print(min([ans1, ans2, ans3]))