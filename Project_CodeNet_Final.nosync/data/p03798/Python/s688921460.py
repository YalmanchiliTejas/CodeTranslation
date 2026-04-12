n = int(input())
s = input()
sw4li = ["SS", "SW", "WS", "WW"]
t = ""
for v in sw4li:
    t = ""
    t += v
    for i in range(1, len(s)):
        if t[-2] == "S" and t[-1] == "S":
            if s[i] == "o":
                t += "S"
            elif s[i] == "x":
                t += "W"
        elif t[-2] == "S" and t[-1] == "W":
            if s[i] == "o":
                t += "W"
            elif s[i] == "x":
                t += "S"
        elif t[-2] == "W" and t[-1] == "S":
            if s[i] == "o":
                t += "W"
            elif s[i] == "x":
                t += "S"
        elif t[-2] == "W" and t[-1] == "W":
            if s[i] == "o":
                t += "S"
            elif s[i] == "x":
                t += "W"
    if t[-1] == t[0]:
        if t[-1] == "S" and t[1] == "S":
            if s[0] == "o":
                if t[-2] == "S":
                    print(t[:-1])
                    exit()
            elif s[0] == "x":
                if t[-2] == "W":
                    print(t[:-1])
                    exit()
        elif t[-1] == "S" and t[1] == "W":
            if s[0] == "o":
                if t[-2] == "W":
                    print(t[:-1])
                    exit()
            elif s[0] == "x":
                if t[-2] == "S":
                    print(t[:-1])
                    exit()
        elif t[-1] == "W" and t[1] == "S":
            if s[0] == "o":
                if t[-2] == "W":
                    print(t[:-1])
                    exit()
            elif s[0] == "x":
                if t[-2] == "S":
                    print(t[:-1])
                    exit()
        elif t[-1] == "W" and t[1] == "W":
            if s[0] == "o":
                if t[-2] == "S":
                    print(t[:-1])
                    exit()
            elif s[0] == "x":
                if t[-2] == "W":
                    print(t[:-1])
                    exit()
print(-1)