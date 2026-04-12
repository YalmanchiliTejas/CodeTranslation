import sys
range = xrange
input = raw_input
 
big = int(2**63 - 1)
big2 = 2**64 - 1
def flipper(x):
    if x > big:
        return int(x - 2**64)
    else:
        return x
 
n = int(input())
S = [int(x) for x in input().split()]
T = [int(x) for x in input().split()]
 
Scount = [[0] for _ in range(2)]
for s in S:
    Scount[0].append((Scount[0][-1] + (s == 0)) & 1)
    Scount[1].append((Scount[1][-1] + (s == 1)) & 1)
 
Tcount = [[0] for _ in range(2)]
for t in T:
    Tcount[0].append((Tcount[0][-1] + (t == 0)) & 1)
    Tcount[1].append((Tcount[1][-1] + (t == 1)) & 1)
 
U = [flipper(int(x)) for x in input().split()]
V = [flipper(int(x)) for x in input().split()]
 
A = [[0] * n for _ in range(n)]

def solve(layer, par):
    ubit = [1 & (u >> layer) for u in U]
    vbit = [1 & (v >> layer) for v in V]
    mat = [[0] * n for _ in range(n)]
    for i in range(n):
        for j in range(n):
            if ubit[i] != S[i]:
                mat[i][j] = ubit[i]
            elif vbit[j] != T[j]:
                mat[i][j] = vbit[j]
            elif S[i] == T[j]:
                mat[i][j] = ubit[i]
            else:
                #assert(S[i] != T[j])
                mat[i][j] = par ^ Scount[S[i]][i] ^ Tcount[T[j]][j]
    
    for i in range(n):
        x = mat[i][0]
        if S[i] == 0:
            for j in range(n):
                x &= mat[i][j]
        else:
            for j in range(n):
                x |= mat[i][j]
        if x != ubit[i]:
            return False
    
    for j in range(n):
        x = mat[0][j]
        if T[j] == 0:
            for i in range(n):
                x &= mat[i][j]
        else:
            for i in range(n):
                x |= mat[i][j]
        if x != vbit[j]:
            return False
    for i in range(n):
        for j in range(n):
            A[i][j] += mat[i][j] << layer
    return True

for layer in range(64):
    if not solve(layer, 0):
        if not solve(layer, 1):
            print -1
            sys.exit()
 
print '\n'.join(' '.join(str(x) for x in row) for row in A)