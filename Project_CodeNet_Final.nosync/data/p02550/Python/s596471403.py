n, x, m = [int(e) for e in input().split()]

s = set()
l = []

a = x % m
total = a
for i in range(1, n):
    a = (a * a) % m
    if a == 0:
        break
    
    if a in s:
        r = n - i
        p = l.index(a)
        
        lo_total = 0
        for j in range(p, len(l)):
            lo_total += l[j]
        total += lo_total * (r // (len(l) - p))

        r %= (len(l) - p)        
        for j in range(p, p + r):
            total += l[j]
        break
    
    s.add(a)
    l.append(a)
    total += a

print(total)