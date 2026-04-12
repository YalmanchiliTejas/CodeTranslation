line = [int(x) for x in input().strip().split()]

N = line[0]
X = line[1]


patties = [1]
buns = [0]
layers = [1]
for i in range(1, 51):
	patties.append(patties[i - 1] * 2 + 1)
	buns.append(buns[i - 1] * 2 + 2)
	layers.append(patties[i] + buns[i])

def answer(l, r, level):
	if (l > r):
		return 0
	if (l == 1 and r == layers[level]):
		return patties[level]

	mid = layers[level] // 2 + 1
	ans = 0
	if (r > mid):
		ans += 1
		ans += answer(1, layers[level - 1], level - 1)
		ans += answer(1, r - mid, level - 1)
	elif (r == mid):
		ans += 1
		ans += answer(1, layers[level - 1], level - 1)
	else:
		ans += answer(1, r - 1, level - 1)
	return ans

print(answer(1, X, N))