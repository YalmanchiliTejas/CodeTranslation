N = int(input())
h = [int(i) for i in input().split()]
count = 1
tmp = h.copy()
for i in range(1, N):
    y = h[i]
    m = max(h[:i])
    if y >= m:
        count += 1
    

print(count)    