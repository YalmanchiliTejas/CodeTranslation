left_string = "qwertasdfgzxcvb"
while True:
    s = input()
    if s == "#":
        break
    ans = 0
    is_left = None
    if s[0] in left_string:
        is_left = True
    else:
        is_left = False

    for i in range(1, len(s)):
        if is_left and s[i] not in left_string:
            ans += 1
            is_left = False
        elif not is_left and s[i] in left_string:
            ans += 1
            is_left = True
    print(ans)
