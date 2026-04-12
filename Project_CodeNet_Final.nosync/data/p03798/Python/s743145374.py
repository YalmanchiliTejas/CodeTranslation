def check():
    N = int(input())
    S = input()
    S = S[1:]+S[0]
    animal = ['W', 'S']
    
    for a in animal:
        for b in animal:
            #print(a,b)
            pre, nex = a, b
            answer = [a,b]
            for i in range(N):
                if nex == 'S':
                    if S[i] == 'o':
                        tmp = nex
                        nex = pre
                        pre = tmp
                        answer.append(nex)
                    elif S[i] == 'x':
                        tmp = nex
                        nex = 'W' if pre == 'S' else 'S'
                        pre = tmp
                        answer.append(nex)
                else:
                    if S[i] == 'o':
                        tmp = nex
                        nex = 'W'if pre == 'S' else 'S'
                        pre = tmp
                        answer.append(nex)
                    elif S[i] == 'x':
                        tmp = nex
                        nex = pre
                        pre = tmp
                        answer.append(nex)
                #print(nex)
            if nex == b and pre == a:
                return answer[:-2]
    else:
        return -1

ans = check()               
if type(ans) == int:
    print(ans)
else:
    print(''.join(ans))