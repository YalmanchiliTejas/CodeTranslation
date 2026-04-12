a,b,c,x,y=map(int,input().split())
case=[]
c=c*2
case.append(a*x+b*y)
if x>=y:
    case.append(c*x)
    case.append(((x-y)*a)+(c*y))
else:
    case.append(y*c)
    case.append(((y-x)*b)+(c*x))
print(min(case))
