x,y,z = input().split()
X = int(x)
Y = int(y)
Z = int(z)

num = int(X/(Y+Z))
if(num*(Y+Z)+Z <=X):
	print(num)
else:
	print(num-1)