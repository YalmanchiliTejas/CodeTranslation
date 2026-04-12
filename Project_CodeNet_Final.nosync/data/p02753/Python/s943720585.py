

S=input()                                               # 1行1列

bl = 0
sh = ' '
for i in S:
	if sh != ' ' and sh != i:
		bl = 1
	sh = i

if bl == 0:
	print('No')
else:
	print('Yes')
