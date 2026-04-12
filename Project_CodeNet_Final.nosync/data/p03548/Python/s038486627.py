x,y,z=map(int,input().split())
a=int(x/(y+z))
b=x%(y+z)
#print(a)
#print(b)
if b==z:
	print(a)
else:
	print(a-1)
