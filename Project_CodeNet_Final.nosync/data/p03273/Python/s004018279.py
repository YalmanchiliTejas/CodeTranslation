H, W = list(map(int, input().split()))  #リスト
A = list(input() for i in range(H)) #スペース抜きの複数行
#A = [input() for _ in range(H)]

B = [False] * H
C = [False] * W

for i in range(H):
    for j in range(W):
        if A[i][j] == "#":
            B[i] = True
            C[j] = True

for i in range(H):
	if B[i]:
		for j in range(W):
			if C[j]:
				print(A[i][j], end = '')
		print()