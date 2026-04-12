a,b,c,x,y = map(int,input().split())
print(min(a*x+b*y,2*c*(max(x,y)),2*c*x+b*max(0,y-x),a*max(0,x-y)+2*c*y))