n,x = map(int, input().split())

pl = [1]
pa = [1]

for i in range(n):
    tmpp = pl[-1]
    tmpa = pa[-1]
    pl.append(tmpp*2+1)
    pa.append(tmpa*2+3)

def largest(n,x):
    if x <= 0:
        return 0
    else:
        if n <= 0:
            if x >= 4:
                return 3
            else:
                return x
        else:
            if x > pa[n]:
                return pl[n] + 1 + largest(n-1, x-2-pa[n])
            elif x == pa[n]:
                return pl[n]
            else:
                return largest(n-1,x-1)

print(largest(n,x))