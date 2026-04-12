h,w = map(int,input().split())
l = [list(input()) for _ in range(h)]
l = [x for x in l if '#' in x]
l = [x for x in zip(*l) if '#' in x]
l = [list(x) for x in zip(*l)]
for x in l:
    print(''.join(x))