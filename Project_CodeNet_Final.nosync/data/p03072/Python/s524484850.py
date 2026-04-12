n = int(input())
h = list(map(int,input().split()))

count = 0

for i in range(n):
	if i == 0 or h[i] == max(h[:i+1]):
		count += 1

print(count)