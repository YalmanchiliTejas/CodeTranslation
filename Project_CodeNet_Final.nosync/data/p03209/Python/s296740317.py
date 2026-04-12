def cnt(n, x):
	if x==0:
		return 0
	elif n==0:
		return 1
	elif x<2**(n+1)-1:
		return cnt(n-1, x-1)
	elif x==2**(n+1)-1:
		return 2**n
	elif x<2**(n+2)-3:
		return cnt(n-1, 2**(n+1)-3) + 1 + cnt(n-1, x-2**(n+1)+1)
	else:
		return 2**(n+1)-1

n, x = map(int, input().split())
print(cnt(n, x))