N = int(input())
s = input()
for t0, t1 in ("SS", "SW", "WS", "WW"):
    t = [""] * N
    t[0] = t0
    t[1] = t1
    for i in range(2, N):
        if t[i-2] == t[i-1]:
            t[i] = "S" if s[i-1] == "o" else "W"
        else:
            t[i] = "W" if s[i-1] == "o" else "S"
    if t[-2] == t[-1]:
        if t[0] != ("S" if s[-1] == "o" else "W"):
            continue
    else:
        if t[0] != ("W" if s[-1] == "o" else "S"):
            continue
    if t[-1] == t[0]:
        if t[1] != ("S" if s[0] == "o" else "W"):
            continue
    else:
        if t[1] != ("W" if s[0] == "o" else "S"):
            continue
    print("".join(t))
    exit()
print(-1)
