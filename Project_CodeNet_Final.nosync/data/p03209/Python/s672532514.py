n, x = map(int, input().split())
ans = 0
def search(level, i):
	global ans
	#print(level, i, ans)
	if level == 0:
		return ans + 1
	if i == 1:
		return ans
	elif i == 2 ** (level + 2) - 3:
		return ans + 2 ** (level + 1) - 1
	elif i == 2 ** (level + 1) - 1:
		return ans + 2 ** level
	elif i < 2 ** (level + 1) - 1:
		return search(level-1, i-1)
	else:
		ans += 2 ** level
		return search(level-1, i - (2 ** (level + 1) - 1))
print(search(n, x))