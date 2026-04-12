while True:
	n = int(input())
	if n == 0:
	    break
	data=[]
	for i in range(n):
	    a=int(input())
	    data.append(a)
	print((sum(data)-max(data)-min(data))//(n-2))
