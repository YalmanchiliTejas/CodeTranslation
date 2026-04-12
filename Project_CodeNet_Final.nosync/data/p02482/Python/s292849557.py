def solve():
	a, b = map(int, raw_input().split())
	if a < b :
		print "a < b"
	elif a == b :
		print "a == b"
	else:
		print "a > b"


if __name__ == "__main__":
	solve()