a,b,c,x,y=[int(x) for x in input().split()]
def gauss(it):
    return max(it,0)
print(min([a*x+b*y,2*c*max(x,y),2*c*min(x,y)+a*gauss(x-min(x,y))+b*gauss(y-min(x,y))]))