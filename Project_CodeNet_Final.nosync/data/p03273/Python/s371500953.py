h, w = map(int, input().split())
a = [tuple(input()) for _ in range(h)]
b = [b for b in a if "#" in b]
c = zip(*[c for c in zip(*b) if "#" in c])
for d in c: print(*d, sep="")