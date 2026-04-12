N = int(input())
H = list(map(int,input().split()))

con = 0

for i in range(N):
	for j in range(i):
		if H[i] < H[j]:
			break
	else:
		con += 1


print(con)