N = int(input())
S = input()
S = S[1:]+S[0]
animal = ['WW', 'WS', 'SW', 'SS']

for pair in animal:
    a,b = pair[0],pair[1]
    pre, nex = a, b
    answer = [a,b]
    for i in range(N):
        if (nex == 'S' and S[i] == 'o') or (nex=='W'and S[i] == 'x'):
            tmp = nex
            nex = pre
            pre = tmp
            answer.append(nex)
        else:
            tmp = nex
            nex = 'W'if pre == 'S' else 'S'
            pre = tmp
            answer.append(nex)
    if nex == b and pre == a:
        print(''.join(answer[:-2]))
        break
else:
    print(-1)