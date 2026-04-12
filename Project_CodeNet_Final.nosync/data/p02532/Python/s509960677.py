stack = []
n = int(raw_input())
for i in range(n):
    stack.append([])

while True:
    s = raw_input().split(" ")
    if s[0] == "push":
        stack[int(s[1])-1].append(s[2])
    elif s[0] == "pop":
        print stack[int(s[1])-1][len(stack[int(s[1])-1])-1]
        stack[int(s[1])-1].pop()
    elif s[0] == "move":
        stack[int(s[2])-1].append(stack[int(s[1])-1][len(stack[int(s[1])-1])-1])
        stack[int(s[1])-1].pop()
    else :
        break