(n, m) = tuple(map(int, input().split()))
(a, b) = zip(*list([input().split() for _ in range(m)]))

pt_c_ns = {}
for i in range(1, n + 1):
    pt_c_ns[str(i)] = []
for i in range(m):
    pt_c_ns[a[i]].append(b[i])
    pt_c_ns[b[i]].append(a[i])

paths_c = ["1"]
for _ in range(n - 1):
    paths_n = []
    for path in paths_c:
        pt_c = path[-1]
        pt_ns = pt_c_ns[pt_c]
        for pt_n in pt_ns:
            if pt_n not in path:
                paths_n.append(path + pt_n)
    paths_c = paths_n[:]

print(len(paths_c))
