stack = [[] for i in range(input() + 1)]
while 1:
    L = raw_input().split()
    if L[0] == 'quit':
        break
    if L[0] == 'push':
        stack[int(L[1])].append(L[2])
    elif L[0] == 'pop':
        print stack[int(L[1])].pop()
    elif L[0] == 'move':
        stack[int(L[2])].append(stack[int(L[1])].pop())