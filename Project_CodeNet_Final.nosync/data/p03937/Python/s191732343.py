H,W = map(int, input().split())
A = [list(map(str, input())) for _ in range(H)]

q = [[0,0]]

while q != []:
	ans = 0
	cx,cy = q.pop()
	A[cx][cy] = "."

	if [cx,cy] == [H-1,W-1]:
		ans = 1
		for i in range(H):
			for j in range(W):
				if A[i][j] == "#":
					ans = 0
		break

	nps = [[cx+1,cy],[cx,cy+1]]
	for nx,ny in nps:
		if 0 <= nx < H and 0 <= ny < W:
			if A[nx][ny] == "#":
				q.append([nx,ny])
				break

if ans:
	print("Possible")
else:
	print("Impossible")