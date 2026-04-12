n,k = map(int,raw_input().split())

ans = 0

if k == 0 :
	print n*n

else:
	for i in range(1,n+1):
		ans += n/i * max(0,i-k) + max(0,n%i-k+1)

	print ans