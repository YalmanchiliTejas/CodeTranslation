n = int(input())
S = list()
minL = 52
res = ''
for i in range(n):
    s = input()
    if len(s) < minL:
        minL = len(s)  
        minS = sorted(s)
    S.append(sorted(s))
    
for i in range(minL):
    ch = minS[i]
    f = 0
    for i in range(len(S)):
        for j in range(len(S[i])):
            if S[i][j] == ch:
                f += 1
                S[i][j] = '1'
                break
            
    if f == len(S):
        res += ch
print(res)
    

    
    