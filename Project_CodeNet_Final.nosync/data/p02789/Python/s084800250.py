from sys import stdin

def main():
	N,M = map(int,stdin.readline().split())
	if(N == M):
		print("Yes")
	else:
		print("No")
main()