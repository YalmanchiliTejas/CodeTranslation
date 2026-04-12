H, Y = map(int, input().split())
P = 0
out = "Possible"
for i in range(H):
	inp = input()
	for j in range(Y):
		if inp[j] == "#" and j > P:
			P = j
		if inp[j] == "#" and j < P:
			out = "Impossible"
print(out)