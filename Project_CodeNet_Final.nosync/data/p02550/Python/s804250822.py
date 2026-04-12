n, x, m = map(int, input().split())
s = x
a = x
note = [0] * m
note[a] += 1
seq = []
for i in range(n-1):
    seq.append(a)
    a = a**2 % m
    if note[a] > 0:
        ind = seq.index(a)
        l = len(seq[ind:])
        n -= len(seq[:ind])
        syo, r = divmod(n, l)
        s = s + sum(seq[ind:]) * (syo-1)
        if r != 0:
            for j in range(ind, ind+r):
                s += seq[j]
        print(s)
        exit()
    if a == 0:
        print(s)
        exit()
    note[a] += 1
    s += a
print(s)
