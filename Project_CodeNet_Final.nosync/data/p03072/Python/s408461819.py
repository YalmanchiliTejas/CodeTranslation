N = int(input())
H = list(map(int, input().split(' ')))

c = 0
m = 0
for h in H:
    if h >= m:
        c += 1
        m = h
print(c)
