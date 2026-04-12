n = int(input())

H = list(map(int,input().split()))
count = 0
highmax = H[0]
for i in range(n):
	if highmax <= H[i]:
		count += 1
		highmax = H[i]

print(count)