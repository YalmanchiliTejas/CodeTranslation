n = int(input())
lst = list(map(int,input().split()))
score = 1
h = lst[0]
for p in range(n-1):
	if lst[p+1] >= h:
		score += 1
		h = lst[p+1]
	else:
		pass
print(score)