N=int(input())
s=input()
for T in ["SS","SW","WS","WW"]:
    for i in range(1,N-1):
        if T[-1]=="S":
            if s[i]=="o":
                T+=T[-2]
            else:
                if T[-2]=="S":
                    T+="W"
                else:
                    T+="S"
        else:
            if s[i]=="x":
                T+=T[-2]
            else:
                if T[-2]=="S":
                    T+="W"
                else:
                    T+="S"
    F=True
    if s[i+1]=="o":
        if T[-1]=="S" and T[-2]==T[0]:
            F=False
        elif T[-1]=="W" and T[-2]!=T[0]:
            F=False
    else:
        if T[-1]=="S" and T[-2]!=T[0]:
            F=False
        elif T[-1]=="W" and T[-2]==T[0]:
            F=False
    if F:
        continue
    F=True
    if s[0]=="o":
        if T[0]=="S" and T[-1]==T[1]:
            F=False
        elif T[0]=="W" and T[-1]!=T[1]:
            F=False
    else:
        if T[0]=="S" and T[-1]!=T[1]:
            F=False
        elif T[0]=="W" and T[-1]==T[1]:
            F=False
    if F:
        continue
    print(T)
    quit()
print(-1)
