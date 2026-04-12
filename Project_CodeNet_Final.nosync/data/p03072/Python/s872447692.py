N = int(input())
H = list(map(int, input().split()))

count = 1 #西の旅館からは見えるため
No = True
for i, hi in enumerate(H):
    if i == 0:
        continue
    No = True
    for j in range(0, i):
        if H[j] > hi:
            No = False
            break
    if No:
        count += 1
print(count)
