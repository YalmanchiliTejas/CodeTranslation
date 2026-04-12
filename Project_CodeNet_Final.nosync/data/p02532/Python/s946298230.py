mount = [[] for i in range(input())]
while True:
    row = raw_input().split()
    if row[0] == 'push':
        mount[int(row[1])-1].append(row[2])
    elif row[0] == 'pop':
        print mount[int(row[1])-1].pop()
    elif row[0] == 'move':
        mount[int(row[2])-1].append(mount[int(row[1])-1].pop())
    elif row[0] == 'quit':
        break