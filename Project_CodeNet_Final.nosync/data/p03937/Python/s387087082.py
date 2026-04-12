H,W=map(int,input().split())
X=[]
count=0
for i in range(H):
	X=input()
	count+=X.count("#")
if count==(H+W-1):
	print("Possible")
else:
	print("Impossible")