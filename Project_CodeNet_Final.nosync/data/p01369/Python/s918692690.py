while True:
    s = raw_input()

    left = "qwertasdfgzxcvb"
    right = "yuiophjklnm"

    if s == "#":
        break

    p = ""
    ans = 0

    for i in range(len(s)):
        if i == 0:
            if s[i] in left:
                p = "left"
            else:
                p = "right"
        elif p == "left" and s[i] in right:
            ans += 1
            p = "right"
        elif p == "right" and s[i] in left:
            ans += 1
            p = "left"

    print ans

