def solve(h, w, a):
    rs = []
    for r in range(h):
        ok = True
        for c in range(w):
            if a[r][c] == "#":
                ok = False
                break
        if not ok:
            rs.append(r)
    cs = []
    for c in range(w):
        ok = True
        for r in range(h):
            if a[r][c] == "#":
                ok = False
                break
        if not ok:
            cs.append(c)
    res = "\n".join(map(lambda r: "".join(map(lambda c: a[r][c], cs)), rs))
    return res

assert solve(4,4,["##.#","....","##.#",".#.#"]) == "###\n###\n.##"
assert solve(3,3,["#..",".#.","..#"]) == "#..\n.#.\n..#"
assert solve(4,5,[".....",".....","..#..","....."]) == "#"
h, w = map(int, raw_input().split())
a = []
for r in range(h):
    a.append(raw_input())
print solve(h, w, a)