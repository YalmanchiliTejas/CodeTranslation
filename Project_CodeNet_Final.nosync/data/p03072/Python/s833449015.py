N = int(input())

H = [int(i) for i in input().split()] 
     
F = 0

for i in range(N-1,0,-1):
	for j in range(i-1,-1,-1):
		if H[i] < H[j]:
			F += 1
			break
print(N - F)