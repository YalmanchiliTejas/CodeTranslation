n = int(input())
a = [input() for _ in range(n)]
s = set(a[0])
for i in a:s = s & set(i)
print(*[ j*min([a[i].count(j) for i in range(n)]) for j in sorted(s)],sep="")