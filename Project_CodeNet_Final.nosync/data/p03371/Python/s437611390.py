A,B,C,X,Y=[int(x) for x in input().split(' ')]

cmin=max([X,Y])
lis=[]
for i in range(cmin+1):
	i_c=i*2
	i_a, i_b=X-i,Y-i
	# print(i_a,i_b,i_c)
	if i_a>=0 and i_b>=0:
		lis.append(i_c*C+i_b*B+i_a*A)
	if i_a<0:
		if i_b<0:
			lis.append(i_c*C)
		else:
			lis.append(i_c*C+i_b*B)
	elif i_b<0:
		lis.append(i_c*C+i_a*A)


print(min(lis))
