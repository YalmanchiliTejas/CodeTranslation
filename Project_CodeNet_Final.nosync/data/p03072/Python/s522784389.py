N = int(input())
H = [int(x) for x in input().split()]

count = 0
high_max = 0

for high in H:
	if high_max <= high:
		count += 1
		high_max = high

print(count)