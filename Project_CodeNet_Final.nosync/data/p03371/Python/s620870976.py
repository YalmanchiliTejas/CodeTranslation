a,b,c,x,y=map(int,input().split())
normal=a*x+b*y
half=c*2*min(x,y)+max(a*(x-y),b*(y-x))
allhalf=c*2*max(x,y)
print(min(half,normal,allhalf))
