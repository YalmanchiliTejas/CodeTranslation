
a,b,c,x,y=map(int,input().split())

def cal(cp):
    res=2*cp*c
    xx=x-cp
    yy=y-cp
    res+=a*max(0,xx)+b*max(0,yy)
    return res

ans=[cal(0),cal(x),cal(y),cal(x+y)]
print(min(ans))