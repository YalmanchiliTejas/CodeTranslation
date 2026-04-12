h, w = map(int, input().split())
a = [input() for _ in range(h)]
a = [x for x in a if not all([i == '.' for i in x])]
b = [[x[i] for x in a] for i in range(w)]
b = ["".join(x) for x in b]
b = [x for x in b if not all([i == '.' for i in x])]
c = [[x[i] for x in b] for i in range(len(b[0]))]
c = ["".join(x) for x in c]
print(*c, sep="\n")