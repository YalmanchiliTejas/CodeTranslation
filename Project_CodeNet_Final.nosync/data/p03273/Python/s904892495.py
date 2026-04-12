h, w, *d = open(0).read().split()
h, w = int(h), int(w)
d = [i for i in d if "#" in i]
d = zip(*[j for j in zip(*d) if "#" in j])
print(*["".join(p) for p in d], sep="\n")