while(True):
	n,l,r = map(int, input().split())
	if (n+l+r)==0:break
	a = list(int(input()) for i in range(n))
	count = 0
	for year in range(l,r+1):
		var = n
		for i in range(n):
			if year%a[i]==0:
				var = i
				break
		if var%2==0:
			count += 1
	print(count)
