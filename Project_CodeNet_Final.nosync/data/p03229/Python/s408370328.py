N = int(input())
L = []
L2 = []
for i in range(N) :
    l = int(input())
    L.append(l)
    L2.append(l)
L = sorted(L)
L2 = sorted(L2)
ANS = []
for i in range(2) :
    ans = 0
    turn = i
    flag = 0
    B = []
    if i == 0 :
        while len(L) != 0 :
            if len(L) == 1 :
                r = L[0]
                L.pop(0)
            else :
                if turn == 0 :
                    p = L[-1]
                    if flag != 0 :
                        ans += abs(p-q)
                    else :
                        B.append(p)
                        flag = 1
                    L.pop(-1)
                    turn = 1
                else :
                    q = L[0]
                    if flag != 0 :
                        ans += abs(p-q)
                    else :
                        B.append(q)
                        flag = 1
                    L.pop(0)
                    turn = 0

        ans += abs(r-B[0])
        ANS.append(ans)
        
    else :
        while len(L2) != 0 :
            if len(L2) == 1 :
                r = L2[0]
                L2.pop(0)
            else :
                if turn == 0 :
                    p = L2[-1]
                    if flag != 0 :
                        ans += abs(p-q)
                    else :
                        B.append(p)
                        flag = 1
                    L2.pop(-1)
                    turn = 1
                else :
                    q = L2[0]
                    if flag != 0 :
                        ans += abs(p-q)
                    else :
                        B.append(q)
                        flag = 1
                    L2.pop(0)
                    turn = 0

        ans += abs(r-B[0])
        ANS.append(ans)
        
        
print(max(ANS))
