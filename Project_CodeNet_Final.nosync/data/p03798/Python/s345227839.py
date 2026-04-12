N = int(input())
S = input()
f = lambda x,y,z: "WS"[(x=="S")^(y=="S")^(z=="o")]
for T in ["SS", "SW", "WS", "WW"]:
    for s in S:
        T += f(T[-1], T[-2], s)
    if T[:2] == T[-2:]:
        print(T[1:-1])
        break
else:
    print(-1)