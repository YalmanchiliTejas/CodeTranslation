num = {0: 'A', 1: 'B', 2: 'C', 3: 'D', 4: 'E'}
while True:
    n = [0] * 5
    for i in range(5):
        s1, s2 = map(int, input().split())
        if s1 == s2 == 0: exit()
        n[i] += s1 + s2
    ans = max(n)
    print(num[n.index(ans)], ans)

