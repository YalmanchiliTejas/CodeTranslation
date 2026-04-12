import sys
input = sys.stdin.readline

N = int(input())
L = [list(input().strip()) for _ in range(N)]

M = []
ANS = {}

for i in range(N):
    M.append({})
    
    for v in L[i]:
        if M[i].get(v) != None:
            M[i][v] += 1
        else:
            M[i][v] = 1

    for k, v in M[i].items():
        if ANS.get(k) != None:
            ANS[k] = min(ANS[k], v)
        else:
            ANS[k] = v

keys = list(ANS.keys())
for k in keys:
    for mv in M:
        if mv.get(k) == None:
            del ANS[k]
            break

if len(ANS) == 0:
    print("")
else:
    keys = list(ANS.keys())
    keys.sort()
    
    for k in keys:
        print(k * ANS[k], end = "")
        
    print("")