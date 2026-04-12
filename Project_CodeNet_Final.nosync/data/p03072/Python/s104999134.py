N = int(input())
H = input().split()
H = [int(x) for x in H]

count = 1
max_height = H[0]

for i in range(N-1) :
	if max_height <= H[i+1] :
		count = count + 1
		max_height = H[i+1]

print(count)