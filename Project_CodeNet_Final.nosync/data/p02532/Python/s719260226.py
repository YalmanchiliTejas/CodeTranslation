s = [[] for n in range(int(raw_input()))]
while True:
    command = raw_input().split()
    if command[0] == 'quit':
        break
    elif command[0] == 'push':
        p, c = int(command[1]), command[2]
        s[p-1].append(c)
    elif command[0] == 'pop':
        p = int(command[1])
        print s[p-1].pop()
    else:
        p1, p2 = int(command[1]), int(command[2])
        s[p2-1].append(s[p1-1].pop())