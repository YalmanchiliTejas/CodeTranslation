while True:
    s = input()
    if s == "#":break
    s = s.split("/")
    area = [0] * len(s)
    for i in range(len(s)):
        t = []
        while True:
            if s[i][0] == "b":
                t.append(1)
                s[i] = s[i][1:]
            else:
                if "b" in s[i]:
                    t += [0] * int(s[i][:s[i].index("b")])
                    s[i] = s[i][s[i].index("b"):]
                else:
                    t += [0] * int(s[i])
                    break
            if s[i] == "":
                break
        area[i] = t
    a, b, c, d = map(int, input().split())
    area[a - 1][b - 1] = 0
    area[c - 1][d - 1] = 1
    t = ""
    for i in range(len(area)):
        j = 0
        while True:
            if area[i][j] == 1:
                t += "b"
                j += 1
            else:
                k = 0
                while j < len(area[i]) and area[i][j] == 0:
                    k += 1
                    j += 1
                t += str(k)
            if j == len(area[i]):break
        if i < len(area) - 1:
            t += "/"
    print(t)
