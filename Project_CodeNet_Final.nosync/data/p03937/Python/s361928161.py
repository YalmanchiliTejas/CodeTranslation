import sys
readline = sys.stdin.readline

H, W = map(int, readline().split())
G = sum(sum(1 if s == '#' else 0 for s in readline().strip()) for _ in range(H))
if G == H+W-1:
    print('Possible')
else:
    print('Impossible')