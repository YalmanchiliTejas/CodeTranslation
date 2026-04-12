h, w, *a = open(0).read().split()
for _ in range(2):
    a = [list(j) for j in zip(*[i for i in a if "#" in i])]
print(*["".join(i) for i in a], sep="\n")
