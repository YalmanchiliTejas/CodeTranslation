def solver(array):
    for index in range(1, n+1):
        if index == n:
            index = 0
        if array[index] == "S" and s[index]:
            if index == n - 1:
                if array[index-1] != array[0]:
                    return False
                else:
                    continue
            if index == 0:
                if array[-1] != array[1]:
                    return False
                else:
                    continue
            array[index + 1] = array[index - 1]
        elif array[index] == "S" and not s[index]:
            if index == n - 1:
                if array[index-1] == array[0]:
                    return False
                else:
                    continue
            if index == 0:
                if array[-1] == array[1]:
                    return False
                else:
                    continue
            if array[index - 1] == "W":
                array[index + 1] = "S"
            else:
                array[index + 1] = "W"
        elif array[index] == "W" and s[index]:
            if index == n - 1:
                if array[index-1] == array[0]:
                    return False
                else:
                    continue
            if index == 0:
                if array[-1] == array[1]:
                    return False
                else:
                    continue
            if array[index - 1] == "W":
                array[index + 1] = "S"
            else:
                array[index + 1] = "W"
        elif array[index] == "W" and not s[index]:
            if index == n - 1:
                if array[index-1] != array[0]:
                    return False
                else:
                    continue
            if index == 0:
                if array[-1] != array[1]:
                    return False
                else:
                    continue
            array[index + 1] = array[index - 1]
    return array


n = int(input())
s = [True if x == "o" else False for x in list(input())]
ws = ["W", "S"] + ["*" for x in range(n - 2)]
sw = ["S", "W"] + ["*" for x in range(n - 2)]
ss = ["S", "S"] + ["*" for x in range(n - 2)]
ww = ["W", "W"] + ["*" for x in range(n - 2)]

for array in [ws, sw, ss, ww]:
    res = solver(array)
    if not res:
        continue
    else:
        print("".join(res))
        exit()
else:
    print(-1)
