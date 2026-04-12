N, X = map(int, input().split())
dp_layer = [1] * (N + 1)
dp_numP = [1] * (N + 1)

for i in range(1, N + 1):
	dp_layer[i] = 3 + 2 * dp_layer[i - 1]
	dp_numP[i] = 1 + 2 * dp_numP[i - 1]
	
x = X
countP = 0
i = N

while x > 0:
	if x >= dp_layer[i]:
		x -= dp_layer[i]
		countP += dp_numP[i]
		if x > 0:
			x -= 1
			countP += 1
	else:
		i -= 1
		x -= 1
		
print(countP)