H, W = map(int, input().split())
L = []
for h in range(H):
    s = input()
    if "#" in s:
        L.append(s)
        continue

S = []
for w in range(W):
    for l in range(len(L)):
        if L[l][w] == "#":
            break
    else:
        S.append(w)
    
for l in range(len(L)):
    s = ""
    for w in range(W):
        if not w in S:
            s += L[l][w]
    print(s)