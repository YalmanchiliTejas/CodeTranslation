h,w = map(int, input().split())
a = [input() for i in range(h)]
a2=[i for i in a if '#' in i]
a3=[i for i in zip(*a2) if '#' in i]
for i in zip(*a3):
    print("".join(i))