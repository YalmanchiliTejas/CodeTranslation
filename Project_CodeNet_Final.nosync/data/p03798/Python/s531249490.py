N=int(input())
S=input()

for fs in ["SS","SW","WW","WS"]:
    ANS=["A"]*N
    ANS[0],ANS[1]=fs[0],fs[1]
    for i in range(2,N):
        if ANS[i-1]=="S":
            if S[i-1]=="o":
                if ANS[i-2]=="S":
                    ANS[i]="S"

                else:
                    ANS[i]="W"

            else:
                if ANS[i-2]=="S":
                    ANS[i]="W"

                else:
                    ANS[i]="S"

        else:
            if S[i-1]=="o":
                if ANS[i-2]=="S":
                    ANS[i]="W"

                else:
                    ANS[i]="S"

            else:
                if ANS[i-2]=="S":
                    ANS[i]="S"

                else:
                    ANS[i]="W"

    if ANS[0]=="S":
        if S[0]=="o":
            if ANS[-1]!=ANS[1]:
                continue
        else:
            if ANS[-1]==ANS[1]:
                continue
    else:
        if S[0]=="o":
            if ANS[-1]==ANS[1]:
                continue
        else:
            if ANS[-1]!=ANS[1]:
                continue

    if ANS[-1]=="S":
        if S[-1]=="o":
            if ANS[-2]!=ANS[0]:
                continue
        else:
            if ANS[-2]==ANS[0]:
                continue
    else:
        if S[-1]=="o":
            if ANS[-2]==ANS[0]:
                continue
        else:
            if ANS[-2]!=ANS[0]:
                continue

    print("".join(ANS))
    break
else:
    print(-1)