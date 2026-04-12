h,w=map(int,input().split())
g=[list(input()) for _ in range(h)]
gg=[]
for l in zip(*g):
	if not all(x=="." for x in l):
		gg.append(l)
ggg=[]
for l in zip(*gg):
	if not all(x=="." for x in l):
		print("".join(l))