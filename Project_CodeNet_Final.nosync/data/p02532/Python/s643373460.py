n = int(input())
s = [[] for i in range(n)]
while True:
    cmd = input().strip().split()
    if cmd[0] == 'push':
        s[int(cmd[1]) - 1].append(cmd[2])
    elif cmd[0] == 'pop':
        print(s[int(cmd[1]) - 1].pop())
    elif cmd[0] == 'move':
        s[int(cmd[2]) - 1].append(s[int(cmd[1]) - 1].pop())
    else:
        break