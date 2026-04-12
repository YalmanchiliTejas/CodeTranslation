h,w = map(int,input().split())
a = [[x for x in input()] for _ in range(h)]

b = []
def solve(ls,i,j,h,w):
	flg = 0
	for k in range(w):
		if ls[i][k] == "#":
			flg += 1
			break
	for l in range(h):
		if ls[l][j] == "#":
			flg += 1
			break
			
	if flg ==2:
		return True
	else:
		return False

			

for i in range(h):
	c = []
	for j in range(w):
		if a[i][j] == "#":
			c.append("#")
		elif solve(a,i,j,h,w):
			c.append(".")
		else:
			pass
	b.append(c)

for i in b:
	print("".join(i))