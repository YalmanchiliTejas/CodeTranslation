x=input().split()
r=int(x[0])
g=int(x[1])
b=int(x[2])
if (10*g+b)%4==0:
	print("YES")
else:
	print("NO")