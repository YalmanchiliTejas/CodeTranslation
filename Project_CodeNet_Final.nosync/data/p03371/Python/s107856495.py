a,b,c,x,y = map(int,input().split())

m = a*x+b*y

for i in range(max(x,y)+1):
	m = min(m,a*max(0,(x-i))+b*max(0,(y-i))+2*c*i)
print(m)