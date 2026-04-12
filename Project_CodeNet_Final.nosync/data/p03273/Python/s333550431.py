h, w = [int(x) for x in input().split()]
a = [j for j in [input() for i in range(h)] if '#' in j]
a = [i for i in zip(*a) if '#' in i]
print('\n'.join(["".join(line) for line in zip(*a)]))
