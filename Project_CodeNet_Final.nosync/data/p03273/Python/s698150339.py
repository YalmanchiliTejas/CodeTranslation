H, W = map(int, input().split())
gr = []
for i in range(H):
	w = input()
	if set(w) == {"."}:
		pass
	else:
		gr.append(w)

gr = [list(x) for x in zip(*gr)]
GR = []
for j in range(W):
	w = gr[j]
	if set(w) == {"."}:
		pass
	else:
		GR.append(w)
GR = [list(x) for x in zip(*GR)]
for i in range(len(GR)):
	print("".join(GR[i]))