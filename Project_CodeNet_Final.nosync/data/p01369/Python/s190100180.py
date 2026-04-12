keysmap = ["qwertasdfgzxcvb","yuiophjklnm"]
while True:
    data = input()
    if data == "#": break
    count = 0
    side = 3
    for c in data:
        for i,keys in enumerate(keysmap):
            if c in keys:
                if side == 3 or side == i:
                    side = i
                else:
                    side = i
                    count += 1
    print(count)
