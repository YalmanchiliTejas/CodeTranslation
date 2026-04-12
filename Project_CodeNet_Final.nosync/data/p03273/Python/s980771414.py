H, W = map(int, input().split())
A = []
for i in range(H):
    l = list(input())
    if not all(a=='.' for a in l):
        A.append(l)
d = []
for i in range(W):
    if all(aa[i]=='.' for aa in A):
        d.append(i)

B = []
for aa in A:
    l = ''
    for i, a in enumerate(aa):
        if i not in d:
            l += a
    B.append(l)
        
for bb in B:
    print(bb)
