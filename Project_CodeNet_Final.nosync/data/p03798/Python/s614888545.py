N = int(input())
S = input()

for a in ["SS", "SW", "WS", "WW"]:
    x = list(a)
    for i in range(N - 2):
        if S[i + 1] == "o":
            if x[i + 1] == "S":
                x.append(x[i])
            else:
                # x[i + 1] == "W"
                if x[i] == "S":
                    x.append("W")
                else:
                    x.append("S")
        else:
            # S[i + 1] == "x"
            if x[i + 1] == "S":
                if x[i] == "S":
                    x.append("W")
                else:
                    x.append("S")
            else:
                x.append(x[i])

    # Check
    mask_n = (x[-1] == "S") and ((S[-1] == "o" and x[-2] == x[0]) \
                                 or (S[-1] == "x" and x[-2] != x[0]))
    mask_n |= (x[-1] == "W") and ((S[-1] == "o" and x[-2] != x[0]) \
                                  or (S[-1] == "x" and x[-2] == x[0]))
    
    mask_1 = (x[0] == "S") and ((S[0] == "o" and x[-1] == x[1]) \
                                or (S[0] == "x" and x[-1] != x[1]))
    mask_1 |= (x[0] == "W") and ((S[0] == "o" and x[-1] != x[1]) \
                                 or (S[0] == "x" and x[-1] == x[1]))

    if mask_n and mask_1:
        print("".join(x))
        break
else:
    print(-1)
