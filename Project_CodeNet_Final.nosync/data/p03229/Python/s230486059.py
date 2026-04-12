n = int(input())
a = [int(input()) for i in range(n)]
a.sort()
ress = []
for i in range(2):
    if i == 0:
        res = 0
        b = a[n//2:]
        c = a[:n//2]
        res += 2*sum(b)
        res -= 2*sum(c)
        res -= b[0]
        if n%2 == 1:
            res -= b[1]
        else:
            res += c[-1]
        ress.append(res)
    if i==1 and n%2==1:
        res = 0
        b = a[n//2+1:]
        c = a[:n//2+1]
        res += 2*sum(b)
        res -= 2*sum(c)
        res += c[-1]+c[-2]
        ress.append(res)
print(max(ress))