from itertools import combinations

s = input()
n = int(s)
l = len(s)
k = int(input())


if k == 1:
	print(9 * (len(s)-1) + int(s[0]))

elif k == 2:
	if len(s) == 1:
		print(0)
	elif len(s) == 2:
		print(n - 9 - n//10)
	else:
		ans = 81 * (l-1) * (l-2) // 2
		for i in range(1, 10):
			for x in range(l-1):
				for j in range(1, 10):
					if i * (10**(l-1)) + j * (10**x) <= n:
						ans += 1
		print(ans)

else:
	if len(s) < 3:
		print(0)
	elif len(s) == 3:
		ans = 0
		for i in range(100, n+1):
			if "0" not in list(str(i)):
				ans += 1
		print(ans)
	else:
		ans = 729 * (l-1) * (l-2) * (l-3) // 6
		ans += (int(s[0])-1) * (l-1) * (l-2) * 81 // 2
		for x, y in combinations(range(l-1), 2):
			for z in range(81):
				j, k = (z//9) + 1, (z%9) + 1
				if int(s[0]) * (10**(l-1)) + j * (10**x) + k * (10**y) <= n:
					ans += 1
		print(ans)