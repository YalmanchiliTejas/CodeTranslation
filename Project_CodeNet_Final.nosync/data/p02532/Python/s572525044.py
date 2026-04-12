stack = [[] for i in range(int(raw_input()))]
ans = []
while True:
	operate = raw_input().split()
	if operate[0] == "quit":
		break
	elif operate[0] == "push":
		stack[int(operate[1])-1].append(operate[2])
	elif operate[0] == "move":
		stack[int(operate[2])-1].append(stack[int(operate[1])-1].pop())
	elif operate[0] == "pop":
		ans.append(stack[int(operate[1])-1].pop())

for s in ans:
	print s