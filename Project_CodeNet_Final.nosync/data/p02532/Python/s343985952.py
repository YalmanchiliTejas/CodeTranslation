n = int(input().strip())
stack = [[] for i in range(n)]
while True:
    line = input().strip().split(" ")
    if line[0] == "quit":
        break
    elif line[0] == "push":
        stack[int(line[1]) - 1].append(line[2])
    elif line[0] == "pop":
        print(stack[int(line[1]) - 1].pop())
    elif line[0] == "move":
        stack[int(line[2]) - 1].append(stack[int(line[1]) - 1].pop())