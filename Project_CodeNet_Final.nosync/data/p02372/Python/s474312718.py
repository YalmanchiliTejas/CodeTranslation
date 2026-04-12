def solve(prev, r, n, dic):
    d = [0] * n
    md = 0
    t = r
    stack = []
    stack += [[prev, r, 0]]
    while stack:
        prev, r, d1 = stack.pop(-1)
        if r in dic:
            for vtx, cost in dic[r]:
                if vtx == prev:
                    continue
                stack += [[r, vtx, d1 + cost]]
                if d[vtx] < d1 + cost:
                    d[vtx] = d1 + cost
                    if md < d[vtx]:
                        md = d[vtx]
                        t = vtx
    return d, t

dic = {}
line = input()
n = int(line)
for _ in range(1, n):
    line = input()
    s, t, w = list(map(int, line.split()))
    if s not in dic:
        dic[s] = [[t, w]]
    else:
        dic[s] += [[t, w]]
    if t not in dic:
        dic[t] = [[s, w]]
    else:
        dic[t] += [[s, w]]
d1, t1 = solve(-1, 0, n, dic)
d2, t2 = solve(-1, t1, n, dic)
d3, t3 = solve(-1, t2, n, dic)
print("\n".join(map(str, [max(a, b) for a, b in zip(d2, d3)] )))
