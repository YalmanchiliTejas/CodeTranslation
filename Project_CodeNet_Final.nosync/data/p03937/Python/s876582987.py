
N, M = input().split()
c=0
for i in range(int(N)):
	a=list(input())
	for j in a:
		if j=="#":
			c+=1

if c==int(N)+int(M)-1:
	print("Possible")
else:
	print("Impossible")