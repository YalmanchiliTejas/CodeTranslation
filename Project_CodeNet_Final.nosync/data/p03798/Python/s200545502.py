n=int(input())
s=[0+(m=="o") for m in input()]

#o:1,x:0
#Sheep:1,wolf:0
def nxt(a,b,m):
	if a==b:
		return m
	else:
		return 1-m

for a,b in ((1,1),(0,1),(1,0),(0,0)):
	c,d = a,b
	ans = [a,b]
	for i in range(n-2):
		a,b = b,nxt(a,b,s[i+1])
		ans.append(b)
	if nxt(a,b,s[-1])==c and nxt(b,c,s[0])==d:
		for x in ans:
			if x:
				print("S",end="")
			else:
				print("W",end="")
		exit()
print(-1)