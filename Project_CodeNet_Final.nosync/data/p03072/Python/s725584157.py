n = int(input())
h = [int(i) for i in input().split()]
count = 0

for i in range(n):
	if max(h[0:i+1])==h[i]:
		count += 1
		
print(count)