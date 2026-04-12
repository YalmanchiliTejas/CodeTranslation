h, w = map(int, input().split())
a = [j for j in [input() for i in range(h)] if '#' in j]
a = [i for i in zip(*a) if '#' in i]
for i in zip(*a):
    print(''.join(i))