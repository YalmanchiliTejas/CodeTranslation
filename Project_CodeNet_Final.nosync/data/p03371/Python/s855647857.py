a,b,c,x,y=list(map(int,input().split()))
money=a*x+b*y

for i in range(max(2*x+1,2*y+1)):
    a_money=max(a*(x-i),0)
    b_money=max(b*(y-i),0)
    money=min(money,a_money+b_money+i*c*2)

print(money)