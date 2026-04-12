h, w = map(int, input().split())
a = [list(input()) for _ in range(h)]

a = list(zip(*[i for i in a if '#' in i]))
a = list(zip(*[i for i in a if '#' in i]))

for n in range(len(a)):
    print("".join(a[n]))
