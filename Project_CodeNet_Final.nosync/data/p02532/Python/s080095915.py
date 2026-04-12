n = int(raw_input())
s = [[] for i in range(n)]
while 1 :
    com = raw_input().split()
    if com[0] == "push":
        s[int(com[1]) - 1].append(com[2])
    elif com[0] == "pop":
        print s[int(com[1]) - 1].pop()
    elif com[0] == "move":
        s[int(com[2]) - 1].append(s[int(com[1]) - 1].pop())
    elif com[0] == "quit":
        break