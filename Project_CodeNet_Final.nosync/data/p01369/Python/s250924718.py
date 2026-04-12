flg = True
inputs = []
while flg:
    inp = input()
    if inp != "#":
        inputs.append(inp)
    else:
        flg = False

right = "yuiophjklnm"
for inp in inputs:
    status = None
    cnt = 0
    for item in inp:
        if status is None:
            if item in right:
                status = "r"
            else:
                status = "l"
            continue
        if status == "r" and item in right:
            continue
        elif status == "l" and item in right:
            status = "r"
            cnt += 1
        elif status == "r" and item not in right:
            status = "l"
            cnt += 1
        elif status == "l" and item not in right:
            continue
    print(cnt)

