H, W = map(int, input().split())
A = [[0 if x == "." else 1 for x in input()] for _ in range(H)]
A = [a for a in A if sum(a) != 0]
W_cut = [w for w in range(W) if sum([a[w] for a in A]) == 0]
for a in A:
    line = ""
    for w in range(W):
        if w in W_cut:
            continue
        line += "." if a[w] == 0 else "#"
    print(line)
