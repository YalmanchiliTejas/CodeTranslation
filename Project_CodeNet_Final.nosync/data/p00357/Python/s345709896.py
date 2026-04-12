N, *D = map(int, open(0).read().split())
ok = 1
e = 0
for i in range(N):
    if e < i:
        ok = 0
    e = max(e, i+D[i]//10)
e = N-1
for i in range(N-1, -1, -1):
    if e > i:
        ok = 0
    e = min(e, i-D[i]//10)
print("yes" if ok else "no")
