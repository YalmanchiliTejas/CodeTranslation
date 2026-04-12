h, w = map(int, input().split())

ls = [list(input()) for i in range(h)]
ls1 = [i for i in ls if '#' in i]
ls2 = [i for i in zip(*ls1) if '#' in i]
ls3 = [i for i in zip(*ls2)]

for i in ls3:
    print(''.join(i))
