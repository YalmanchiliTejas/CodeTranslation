a,b,c,x,y=map(int,input().split())

aaa=[]

aaa.append(2*c*max([x,y]))
aaa.append(a*x+b*y)

if x > y:
    aaa.append(2*c*y+a*(x-y))
elif x < y:
    aaa.append(2*c*x+b*(y-x))

print(min(aaa))