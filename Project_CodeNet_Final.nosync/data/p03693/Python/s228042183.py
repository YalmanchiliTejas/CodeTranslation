R,G,B=map(int,input().split())
A=R*100+G*10+B
if A%4==0:
	print("YES")
else:
	print("NO")