n = input()
mountains = [[] for x in range(1,n+1)]
popblock = []
while True:
	x = map(str,raw_input().split(' '))
	if x[0] == 'quit':
		break
	else:
		mt_num = int(x[1])-1
		if x[0] == 'push':
			mountains[mt_num].insert(0,x[2])
		elif x[0] == 'pop':
			popblock.append(mountains[mt_num][0])
			del mountains[mt_num][0]
		elif x[0] == 'move':
			mt_num2 = int(x[2])-1
			mountains[mt_num2].insert(0,mountains[mt_num][0])
			del mountains[mt_num][0]
		continue
for val in popblock:
	print val