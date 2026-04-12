n = int(input())
h = list(map(int,(input().strip().split(' '))))
m = h[0]
t = 1
for i in range(1, len(h)):
    if m <= h[i]:
        m = h[i]
        t += 1
print(t)