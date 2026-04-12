store = "ABCDE"

while 1:
    s1, s2 = map(int, input().split())
    if s1 == 0 and s2 == 0:
        break

    s = store[0]
    ans = s1 + s2

    for i in range(4):
        s1, s2 = map(int, input().split())
        if s1 + s2 > ans:
            s, ans = store[i+1], s1 + s2

    print(s, ans)

