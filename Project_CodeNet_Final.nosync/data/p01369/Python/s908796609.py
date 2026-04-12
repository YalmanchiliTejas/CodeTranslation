left = list("qwertasdfgzxcvb")
right = list("yuiophjklnm")

while 1:
    S = list(input())
    if S == ["#"]:
        break

    cnt = 0
    s = S.pop(0)
    if s in left:
        pos = 0
    else:
        pos = 1

    for s in S:
        if pos == 0 and s in right:
            cnt += 1
            pos = 1
        elif pos == 1 and s in left:
            cnt += 1
            pos = 0

    print(cnt)

