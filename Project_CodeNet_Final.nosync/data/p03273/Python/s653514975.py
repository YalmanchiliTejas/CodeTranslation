h,w = map(int,input().split())
a = [input() for _ in range(h)]
while "."*w in a:
	a.remove("."*w)
lena = len(a)
b = ["".join([a[i][j] for i in range(lena)]) for j in range(w)]
while "."*lena in b:
	b.remove("."*lena)
c = [[b[i][j] for i in range(len(b))] for j in range(len(a))]
for i in c:
	print("".join(i))