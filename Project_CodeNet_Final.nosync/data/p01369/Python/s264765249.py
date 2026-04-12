L = "qwertasdfgzxcvb"

while 1:
    x = raw_input()
    if x == "#":
        break
    lst = []
    ans = 0
    for i in range(len(x)):
        if x[i] in L:
            lst.append("L")
            if i != 0:
                if lst[i-1] == "R":
                    ans += 1
        else:
            lst.append("R")
            if i != 0:
                if lst[i-1] == "L":
                    ans += 1
    print ans