H,W = map(int,input().split())
A = []
for h in range(H):
    a = input()
    if '#' in a:
        A.append(a)
A = [a for a in zip(*A) if '#' in a]
A = [a for a in zip(*A)]
for a in A:
    print(''.join(a))