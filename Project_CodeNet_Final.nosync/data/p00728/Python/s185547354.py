def totalize(n):
    total = 0
    mins, maxs = (int(input()) for _ in range(2))
    if maxs < mins:
        maxs, mins = mins, maxs
    for _ in range(n - 2):
        s = int(input())
        if s < mins:
            s, mins = mins, s
        elif maxs < s:
            s, maxs = maxs, s
        total += s
    return total // (n - 2)

while True:
    n = int(input())
    if n == 0:
        break
    print(totalize(n))