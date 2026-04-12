import sys
input = sys.stdin.readline
from operator import itemgetter

def main():
	h, w = map(int, input().strip().split())
	a = [[] for _ in range(h)]
	for i in range(h):
		a[i] = list(input().strip())
	for i in range(h):
		flag = True
		for j in range(w):
			if a[i][j] == '#':
				flag = False
				break
		if flag:
			a[i] = [-1] * w
	for j in range(w):
		flag = True
		for i in range(h):
			if a[i][j] == '#':
				flag = False
				break
		if flag:
			for i in range(h):
				a[i][j] = -1
	# print(a)
	for i in range(h):
		for j in range(w):
			if a[i][j] != -1:
				print("{}".format(a[i][j]), end="")
		print("")
if __name__ == '__main__':
	main()
