H,W = map(int,input().split())
src = [input() for i in range(H)]
cols = list(zip(*src))
for row in src:
    if all([c=='.' for c in row]): continue
    out = ''
    for i,c in enumerate(row):
        if all([c=='.' for c in cols[i]]): continue
        out += c
    print(out)