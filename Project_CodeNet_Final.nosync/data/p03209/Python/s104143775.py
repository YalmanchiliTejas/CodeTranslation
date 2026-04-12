import sys
input = sys.stdin.readline
from functools import lru_cache

size = [0] * 51

@lru_cache(100000)
def rec(l, x):
	global size
	# print(l, x)
	if l == 0:
		# print(x)
		return x
	mid = size[l] // 2 + 1
	if x == size[l]:
		return 2 * rec(l-1, size[l-1]) + 1
	elif x == mid:
		return rec(l-1, size[l-1]) + 1
	elif x == 1:
		return 0
	elif x > mid:
		return rec(l-1, size[l-1]) + rec(l-1, x-size[l-1]-2) + 1
	else:
		return rec(l-1, x-1)

def main():
	global size
	n, x = map(int, input().strip().split())
	size[0] = 1
	for i in range(1, 51):
		size[i] = 2 * size[i-1] + 3
	# print(rec(1, size[1]))
	print(rec(n, x))

if __name__ == '__main__':
	main()
