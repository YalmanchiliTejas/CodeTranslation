x,y,z = map(int, input().split())
for i in range (1,102000):
	if y*i+z*(i+1) > x:
		print(i-1)
		exit()
