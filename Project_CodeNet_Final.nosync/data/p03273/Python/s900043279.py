H,W = map(int, input().split())
A = [input() for _ in range(H)]
A = [a for a in A if a != '.'*W]
A_t = [list(a) for a in zip(*A)]
A_t = [list(a) for a in A_t if '#' in a]
A = [a for a in zip(*A_t)]

for i in range(len(A)):
	print("".join(A[i]))