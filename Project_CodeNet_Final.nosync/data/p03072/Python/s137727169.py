n = int(input())
h = list(map(int, input().split()))
a = 1

for i in range(1, n):
    s = True
    for j in range(i):
        if h[i] < h[j]:
            s = False
            break
    if s:
        a += 1

print(a)
