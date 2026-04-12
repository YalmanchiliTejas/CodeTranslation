mountain = map(lambda x:[], range(int(raw_input())))
removed = []
while True:
    command = raw_input().split()
    if command[0] == 'push':
        mountain[int(command[1]) - 1].append(command[2])
    elif command[0] == 'pop':
        removed.append(mountain[int(command[1]) - 1][-1])
        mountain[int(command[1]) - 1].pop(-1)
    elif command[0] == 'move':
        mountain[int(command[2]) - 1].append(mountain[int(command[1]) - 1][-1])
        mountain[int(command[1]) - 1].pop(-1)
    elif command[0] == 'quit':
        break
for block in removed:
    print block