a,b,c,x,y=map(int,input().split())
print(min(a+b,2*c)*min(x,y)+[0,min(a,2*c)*(x-y),min(b,2*c)*(y-x)][(x>y)+2*(x<y)])