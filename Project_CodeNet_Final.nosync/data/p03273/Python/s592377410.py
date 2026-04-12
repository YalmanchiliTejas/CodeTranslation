H, W = map(int, input().split())

lst = [input() for i in range(H)]

ans = []
for i in range(W):
	row = [j[i] for j in lst]
	if ("".join(row) != "." * H):
		ans.append("".join(row))

for i in range(H):
	row = [j[i] for j in ans]
	if ("".join(row) != "." * len(row)):
		print("".join(row))
