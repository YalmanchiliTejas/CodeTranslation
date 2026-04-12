a,b,c,x,y=map(int,input().split())
print(min(a*max(0,(x-i))+b*max(0,(y-i))+2*c*i for i in range(max(x,y)+1)))