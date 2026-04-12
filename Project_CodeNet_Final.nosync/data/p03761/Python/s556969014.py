n = int(input())
s = [input() for _ in range(n)]

for i in "abcdefghijklmnopqrstuvwxyz":
    m = 100
    for j in range(n):
        m = min(m, s[j].count(i))

    for k in range(m):
        print(i, end='')
