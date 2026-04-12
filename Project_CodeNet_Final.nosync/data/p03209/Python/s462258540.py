n, eat = map(int, input().split())

pattiesCount = lambda level: (1 << (level + 1)) - 1
bunsCount = lambda level: (1 << (level + 1)) - 2
bothCount = lambda level: (1 << (level + 2)) - 3

# for i in range(51):
#     if pattiesCount(i) != p[i]:
#         raise Exception()
#     print(i, '->', pattiesCount(i), bunsCount(i), bothCount(i))

def doit(level, eat):
    if level == 0:
        return int(eat >= 1)
    both = bothCount(level - 1)
    patties = pattiesCount(level - 1)
    if eat == both + 2:
        return 1 + patties
    if eat > both + 1:
        return 1 + patties + doit(level - 1, eat - 2 - both)
    return doit(level - 1, eat - 1)

print(doit(n, eat))
