n = int(input())
hs = list(map(int, input().split()))
ms = [hs[0]]
for h in hs[1:]:
    m = ms[-1]
    if m >= h:
        ms.append(m)
    else:
        ms.append(h)
count = 0
for h, m in zip(hs, ms):
    if h >= m:
        count += 1
print(count)