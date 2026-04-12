H, W = map(int, input().split())
A = [list(input()) for i in range(H)]

A = [a for a in A if ('#' in a)]
A = [a for a in zip(*A) if ('#' in a)]
A = zip(*A)

for a in A:
    print(''.join(a))
