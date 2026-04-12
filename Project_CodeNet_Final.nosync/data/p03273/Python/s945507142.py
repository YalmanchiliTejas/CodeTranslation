H,W = map(int,input().split())
A = [list(input()) for h in range(H)]
A1 = [a for a in A if '#' in a]
A2 = [a for a in zip(*A1) if '#' in a]
A3 = [a for a in zip(*A2)]
for a in A3:
    print(''.join(a))