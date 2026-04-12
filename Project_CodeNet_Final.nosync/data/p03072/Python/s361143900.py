N = int(input())
H = [int(j) for j in input().split()]
count = 1
for j in range(1,N):
	if H[j] >= max([H[k] for k in range(0,j)]):
		count = count + 1
print(count)
	