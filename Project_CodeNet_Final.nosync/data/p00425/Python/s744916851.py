ans = []
while True:
    place = range(1,7)
    n = input()
    if n == 0:
        break
    p = 0
    sig = 1
    while p != n:
        direct = raw_input()
        if direct == "North":
            temp = place[1]
            place[1] = place[5]
            place[5] = place[4]
            place[4] = place[0]
            place[0] = temp
            sig += temp
        elif direct == "East":
            temp = place[3]
            place[3] = place[5]
            place[5] = place[2]
            place[2] = place[0]
            place[0] = temp
            sig += temp
        elif direct == "West":
            temp = place[2]
            place[2] = place[5]
            place[5] = place[3]
            place[3] = place[0]
            place[0] = temp
            sig += temp
        elif direct == "South":
            temp = place[4]
            place[4] = place[5]
            place[5] = place[1]
            place[1] = place[0]
            place[0] = temp
            sig += temp
        elif direct == "Right":
            temp = place[1]
            place[1] = place[2]
            place[2] = place[4]
            place[4] = place[3]
            place[3] = temp
            sig += place[0]
        elif direct == "Left":
            temp = place[1]
            place[1] = place[3]
            place[3] = place[4]
            place[4] = place[2]
            place[2] = temp
            sig += place[0]
        p += 1
    ans.append(sig)

for i in ans:
    print i