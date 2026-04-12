a,b,c,x,y=map(int,input().split())
d= a*x+b*y
e= 2*c*x+b*max(0,y-x) #yが多い
f= 2*c*y+a*max(0,x-y) #xが多い
print(min(d,e,f))