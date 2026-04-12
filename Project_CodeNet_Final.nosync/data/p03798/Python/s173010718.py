N=int(input())
S=list(input())
S.append(S[0])
S.append(S[1])

L1=["S","S"]
L2=["S","W"]
L3=["W","S"]
L4=["W","W"]

flag=0

for i in range(1,len(S)-1):
    if L1[i]=="S":
        if S[i]=="o" and L1[i-1]=="S":
            L1.append("S")
        elif S[i]=="o" and L1[i-1]=="W":
            L1.append("W")
        elif S[i]=="x" and L1[i-1]=="S":
            L1.append("W")
        elif S[i]=="x" and L1[i-1]=="W":
            L1.append("S")
    else:
        if S[i]=="o" and L1[i-1]=="S":
            L1.append("W")
        elif S[i]=="o" and L1[i-1]=="W":
            L1.append("S")
        elif S[i]=="x" and L1[i-1]=="S":
            L1.append("S")
        elif S[i]=="x" and L1[i-1]=="W":
            L1.append("W")
if L1[0]==L1[len(L1)-2] and L1[1]==L1[len(L1)-1]:
    L1=L1[:N]
    print("".join(L1))
    exit()
    
for i in range(1,len(S)-1):
    if L2[i]=="S":
        if S[i]=="o" and L2[i-1]=="S":
            L2.append("S")
        elif S[i]=="o" and L2[i-1]=="W":
            L2.append("W")
        elif S[i]=="x" and L2[i-1]=="S":
            L2.append("W")
        elif S[i]=="x" and L2[i-1]=="W":
            L2.append("S")
    else:
        if S[i]=="o" and L2[i-1]=="S":
            L2.append("W")
        elif S[i]=="o" and L2[i-1]=="W":
            L2.append("S")
        elif S[i]=="x" and L2[i-1]=="S":
            L2.append("S")
        elif S[i]=="x" and L2[i-1]=="W":
            L2.append("W")
if L2[0]==L2[len(L2)-2] and L2[1]==L2[len(L2)-1]:
    L2=L2[:N]
    print("".join(L2))
    exit()
    
for i in range(1,len(S)-1):
    if L3[i]=="S":
        if S[i]=="o" and L3[i-1]=="S":
            L3.append("S")
        elif S[i]=="o" and L3[i-1]=="W":
            L3.append("W")
        elif S[i]=="x" and L3[i-1]=="S":
            L3.append("W")
        elif S[i]=="x" and L3[i-1]=="W":
            L3.append("S")
    else:
        if S[i]=="o" and L3[i-1]=="S":
            L3.append("W")
        elif S[i]=="o" and L3[i-1]=="W":
            L3.append("S")
        elif S[i]=="x" and L3[i-1]=="S":
            L3.append("S")
        elif S[i]=="x" and L3[i-1]=="W":
            L3.append("W")
if L3[0]==L3[len(L3)-2] and L3[1]==L3[len(L3)-1]:
    L3=L3[:N]
    print("".join(L3))
    exit()
    
for i in range(1,len(S)-1):
    if L4[i]=="S":
        if S[i]=="o" and L4[i-1]=="S":
            L4.append("S")
        elif S[i]=="o" and L4[i-1]=="W":
            L4.append("W")
        elif S[i]=="x" and L4[i-1]=="S":
            L4.append("W")
        elif S[i]=="x" and L4[i-1]=="W":
            L4.append("S")
    else:
        if S[i]=="o" and L4[i-1]=="S":
            L4.append("W")
        elif S[i]=="o" and L4[i-1]=="W":
            L4.append("S")
        elif S[i]=="x" and L4[i-1]=="S":
            L4.append("S")
        elif S[i]=="x" and L4[i-1]=="W":
            L4.append("W")
if L4[0]==L4[len(L4)-2] and L4[1]==L4[len(L4)-1]:
    L4=L4[:N]
    print("".join(L4))
    exit()

print(-1)