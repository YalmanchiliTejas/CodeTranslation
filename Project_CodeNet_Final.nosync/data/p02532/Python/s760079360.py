res = [[] for i in range(input())]
while 1:
	s = raw_input().split()
	if s[0] == "quit" :
		break
	if s[0] == "move" :
		res[int(s[2])-1].append(res[int(s[1])-1].pop())
	if s[0] == "push" :
		res[int(s[1])-1].append(s[2])
	if s[0] == "pop" :
		print res[int(s[1])-1].pop()