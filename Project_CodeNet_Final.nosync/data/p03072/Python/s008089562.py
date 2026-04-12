# input data
n = int(input())
h = list(map(int, input().split()))

# solve
ans = 0
maxHeight = 0

for i in range(0, n):
	if h[i] >= maxHeight:
		maxHeight = h[i]
		ans += 1
  
print(ans)
