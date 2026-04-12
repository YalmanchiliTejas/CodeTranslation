n = int(input())
stack = []
for i in range(n):
    stack.append([])
while True:
    order = list(input().split())
    if order[0] == 'push':
        stack[int(order[1])-1].append(order[2])
    elif order[0] == 'pop':
        print(stack[int(order[1])-1].pop())
    elif order[0] == 'move':
        stack[int(order[2])-1].append(stack[int(order[1])-1].pop())
    elif order[0] == 'quit':
        break