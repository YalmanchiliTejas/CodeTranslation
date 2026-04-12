a,b,c,x,y=map(int,input().split())
print(min(a*max(x-i,0)+b*max(y-i,0)+2*c*i for i in range(max(x,y)+1)))