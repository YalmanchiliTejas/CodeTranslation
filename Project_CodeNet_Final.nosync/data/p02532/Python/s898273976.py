#!/opt/local/bin/python
#coding:UTF-8
#スタック2
num = int(raw_input())
#stack = [[]]*num
stack = [[] for x in xrange(num) ]
while True:
	order = raw_input().split()
	if order[0] == "quit":
		break
	elif order[0] == "push":
		order[1] = int(order[1])
		stack[(order[1] - 1)].append(order[2])
	elif order[0] == "move":
		order[1] = int(order[1])
		order[2] = int(order[2])
		stack[(order[2] - 1)].append(stack[(order[1] - 1)].pop())
	elif order[0] == "pop":
		order[1] = int(order[1])
		print stack[(order[1] - 1)].pop()