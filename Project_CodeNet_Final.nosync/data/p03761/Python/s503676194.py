n = int(input())
a = list(input() for _ in range(n))
# n = 3
# a = ["cbaa","daacc","acacac"]
s = ""
for c in a[0]:
    f = []
    for i in range(n-1):
        if c not in a[i+1]:
            break
        for d in range(len(a[i+1])):
            if c == a[i+1][d]:
                f.append(d)
                break
    else:
        s += str(c)
        for i in range(n-1):
            a[i+1] = a[i+1][:f[i]] +""+ a[i+1][f[i]+1:]
        
ns = "".join(sorted(s))
print(ns)