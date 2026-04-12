n = int(input())
h = list(map(int, input().split()))
c = 1
H = h[0]
for i in h[1:]:
    if i >= H:
        c += 1
    H = max(H, i)
print(c)