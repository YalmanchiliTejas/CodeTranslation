H,W=map(int,input().split())
A=[list(input()) for _ in range(H)]

A=[a for a in A if '#' in a]
A=zip(*[a for a in zip(*A) if '#' in a])

for a in A:
    print(''.join(a))