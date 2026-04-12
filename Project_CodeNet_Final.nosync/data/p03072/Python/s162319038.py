n = int(input())
hs = list(map(int, input().split()))
count = 0
for i in range(n):
    if i == 0:
        count += 1
        continue
    ok = True
    for j in range(i):
        if hs[j] > hs[i]:
            ok = False
            break
    if ok:
        count += 1
print(count)
