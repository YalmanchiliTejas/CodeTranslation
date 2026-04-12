N = int(input())
S = input()


A = ["SS", "SW", "WS", "WW"]

for j in range(4) :
    t = A[j]
    for i in range(1,N) :
        if S[i] == "o" :
            if t[i] == "S" :
                if t[i-1] == "S" :
                    t += "S"
                else :
                    t += "W"
            else :
                if t[i-1] == "S" :
                    t += "W"
                else :
                    t += "S"
        else :
            if t[i] == "S" :
                if t[i-1] == "S" :
                    t += "W"
                else :
                    t += "S"
            else :
                if t[i-1] == "S" :
                    t += "S"
                else :
                    t += "W"
    
    if t[0] == t[-1] :
        if S[0] == "o" and t[0] == "S" and (t[-2] == t[1]) :
            print(t[:-1])
            break
        elif S[0] == "o" and (t[0] == "W") and (t[-2] != t[1]) :
            print(t[:-1])
            break
        if S[0] == "x" and t[0] == "S" and (t[-2] != t[1]) :
            print(t[:-1])
            break
        elif S[0] == "x" and (t[0] == "W") and (t[-2] == t[1]) :
            print(t[:-1])
            break
else :
    print(-1)
