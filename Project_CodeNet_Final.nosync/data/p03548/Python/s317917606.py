x,y,z=map(int,input().split())
max=0
for i in range(1,x+1):
	if i*y+(i+1)*z<=x:
		max=i
	if x<i*y+(i+1)*z:
		break
print(max)