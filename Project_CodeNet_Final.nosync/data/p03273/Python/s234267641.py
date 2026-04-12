h, w = map(int, input().split())
a = [list(input()) for _ in range(h)]
a = [c for c in zip(*a) if '#' in c]
a = [r for r in zip(*a) if '#' in r]
for r in a:
    print(''.join(r))