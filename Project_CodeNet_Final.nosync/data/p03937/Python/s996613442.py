H, W = map(int, input().split())
ans = 0
for i in range(H) :
    ans += input().count('#')
if ans == H+W-1:
	print("Possible")
else:
	print("Impossible")