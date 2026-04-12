n=int(input())
s=[input() for num in range(n)]
for i in range(97,97+26,1):
	list=[]
	for j in range(n):
		list.append(s[j].count(chr(i)))
	print(chr(i)*min(list),end="")