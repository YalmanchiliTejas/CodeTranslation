X,Y,Z = map(int,input().split())
count = 0
before = 0
I = Z
while (True):
	I += Y + Z
	
	if I > X:
		break
	
	count += 1
	
print(count)