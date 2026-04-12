import sys
input = sys.stdin.readline

def main():
	x = int(input().strip())
	if x == 3 or x == 5 or x == 7:
		print('YES')
	else:
		print('NO')

if __name__ == '__main__':
	main()
