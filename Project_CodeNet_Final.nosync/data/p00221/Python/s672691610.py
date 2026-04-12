def fizzbuzz(n):
	if n%15==0: return "FizzBuzz"
	if n%3==0: return "Fizz"
	if n%5==0: return "Buzz"
	return str(n)
while 1:
	try:
		m,n=map(int,raw_input().split())
		if m==0:break
		player=range(1,m+1)
		p=0
		for i in range(n):
			if fizzbuzz(i+1)!=raw_input():
				del player[p]
				m=len(player)
				if m==1:
					break
				p%=m
			else:
				p=(p+1)%m
		print " ".join(map(str,player))
	except:
		pass