n, x = map(int, input().split())

if x == 1:
    print(0)
    exit()

b = [0 for _ in range(n + 1)]
p = [0 for _ in range(n + 1)]

b[0] = 1
p[0] = 1

for i in range(1, n + 1):
    b[i] = b[i - 1] * 2 + 3
    p[i] = p[i - 1] * 2 + 1

def burger(s, t):
    if t == 0:
        return 0
    if s == 0:
        return 1
    if t <= b[s - 1]:
        return burger(s - 1, t - 1)
    elif t == b[s - 1] + 1:
        return p[s - 1]
    elif t == b[s - 1] + 2:
        return p[s - 1] + 1
    else:
        return burger(s - 1, t - b[s - 1] - 2) + p[s - 1] + 1

print(burger(n, x))
