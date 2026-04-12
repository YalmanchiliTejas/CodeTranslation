x,y,z = map(int,input().split())
count = 0
while ((y + z)*count + z) <= x:
	count += 1
print(count - 1)