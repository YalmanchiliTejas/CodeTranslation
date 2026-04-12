import sys

def input():
    return sys.stdin.readline()[:-1]


S = input()

if 'A' in S and 'B' in S:
	print("Yes")
else:
	print("No")
