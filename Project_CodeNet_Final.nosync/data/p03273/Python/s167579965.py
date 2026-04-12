h, w = map(int, input().split())
m = [list(input()) for _ in range(h)]
mr = [r for r in m if '#' in r]
mrc = [c for c in zip(*mr) if '#' in c]
print(*(''.join(row) for row in zip(*mrc)), sep='\n')