n = (int)(raw_input())
b = [[] for i in range(n+1)]
while True:
	com = raw_input().split()
	if com[0] == "quit":
		break
	elif com[0] == "push":
		com[1] = int(com[1])
		b[com[1]].append(com[2])
	elif com[0] == "move":
		com[1] = int(com[1])
		com[2] = int(com[2])
		tmp = b[com[1]].pop()
		b[com[2]].append(tmp)
	elif com[0] == "pop":
		com[1] = int(com[1])
		print(b[com[1]].pop())