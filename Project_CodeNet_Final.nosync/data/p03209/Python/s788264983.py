import sys
sys.setrecursionlimit(10**6)

def main():
	n,x=map(int,input().split())
	ans = 0
	for i in range(n, -1, -1):
		if x == 0:
			break
		m = 4*(2**i)-3
		if x == m:
			ans += 2**(i+1) - 1
			break
		if x >= (m+1)/2:
			ans += 2**(i)
			x -= int((m+1)/2)
		else:
			x -= 1
	print(ans)
	return
main()