H, W = map(int, input().split())
li = []
for i in range(H):
	x = input()
	if "#" in x:
		li.append(x)

H = len(li)
W = len(li[0])

removelist = []
for i in range(W):
	for j in range(H):
		if li[j][i] == "#":
			break
	else:
		removelist.append(i)

for i in reversed(removelist):
	for j in range(H):
		li[j] = li[j][:i] + li[j][i+1:]

for i in range(H):
	print(li[i])
