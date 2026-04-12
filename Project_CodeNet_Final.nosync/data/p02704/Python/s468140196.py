# F - I hate Matrix Construction

n = int(input())
s = list(map(int, input().split()))
t = list(map(int, input().split()))
u = list(map(int, input().split()))
v = list(map(int, input().split()))
assert len(s) == len(t) == n
assert len(u) == len(v) == n

nbits = 64
AND = 0
OR  = 1

A = [[u[i]] * n for i in range(n)]
for i in range(n):
    for j in range(n):
        if t[j] == AND:
            A[i][j] |= v[j]  # v[j]で1のビットは1
        else:
            A[i][j] &= v[j]  # v[j]で0のビットは0
        # conflict check
        if (s[i] == AND and t[j] == OR  and  u[i] & ~v[j]) or \
           (s[i] == OR  and t[j] == AND and ~u[i] &  v[j]):
            print(-1)
            exit()

# 1であるビット数を数える
ucount = [[0] * nbits for i in range(n)]
vcount = [[0] * nbits for j in range(n)]
for i in range(n):
    for j in range(n):
        for k in range(nbits):
            if A[i][j] & (1 << k):
                ucount[i][k] += 1
                vcount[j][k] += 1

for k in range(nbits):
    mask = 1 << k
    for i in range(n):
        if s[i] == OR and u[i] & (1 << k) and ucount[i][k] == 0:
            # いずれかの列の第kビットを1にする
            for j in range(n):
                if (t[j] == OR  and v[j] & mask) or \
                   (t[j] == AND and v[j] & mask == 0 and vcount[j][k] < n - 1):
                    A[i][j] |= mask
                    ucount[i][k] += 1
                    vcount[j][k] += 1
                    break
            else:
                print(-1)
                exit()
        if s[i] == AND and u[i] & mask == 0 and ucount[i][k] == n:
            # いずれかの列の第kビットを0にする
            for j in range(n):
                if (t[j] == AND and v[j] & mask == 0) or \
                   (t[j] == OR  and v[j] & mask and vcount[j][k] > 1):
                    A[i][j] &= ~mask
                    ucount[i][k] -= 1
                    vcount[j][k] -= 1
                    break
            else:
                print(-1)
                exit()
    for j in range(n):
        if t[j] == OR and v[j] & mask and vcount[j][k] == 0:
            for i in range(n):
                if (s[i] == OR  and u[i] & mask) or \
                   (s[i] == AND and u[i] & mask == 0 and ucount[i][k] < n - 1):
                    A[i][j] |= mask
                    ucount[i][k] += 1
                    vcount[j][k] += 1
                    break
            else:
                print(-1)
                exit()
        if t[j] == AND and v[j] & mask == 0 and vcount[j][k] == n:
            for i in range(n):
                if (s[i] == AND and u[i] & mask == 0) or \
                   (s[i] == OR  and u[i] & mask and ucount[i][k] > 1):
                    A[i][j] &= ~mask
                    ucount[i][k] -= 1
                    vcount[j][k] -= 1
                    break
            else:
                print(-1)
                exit()

for i in range(n):
    print(' '.join(map(str, A[i])))
