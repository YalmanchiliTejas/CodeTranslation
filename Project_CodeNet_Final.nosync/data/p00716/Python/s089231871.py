for _ in range(input()):
	asset = ans = input()
	year = input()
	n = input()
	for i in range(n):
		plan,rate,cost = map(float,raw_input().split())
		if plan == 0.0:
			ans = max(ans,sum(int(rate*(asset - y*cost)) for y in range(year)) + asset - year*cost)
		else:
			cur = asset
			for y in range(year):
				cur = int(cur*(1 + rate) - cost)
			ans = max(ans,cur)
	print int(ans)