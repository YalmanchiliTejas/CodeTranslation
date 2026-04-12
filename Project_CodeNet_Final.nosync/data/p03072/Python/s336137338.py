N = int(input())
H = list(map(int,input().split()))
max_H = 0
sum = 0
for i in range(N):
	if max_H <= H[i]:
		max_H = H[i]
		sum += 1
print(sum)