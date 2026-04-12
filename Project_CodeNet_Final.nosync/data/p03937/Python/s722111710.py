H, Y = map(int, input().split())
P = 0
K = 0
for i in range(H):
	K += input().count("#")
if K == H + Y - 1:
	print("Possible")
else:
	print("Impossible")
