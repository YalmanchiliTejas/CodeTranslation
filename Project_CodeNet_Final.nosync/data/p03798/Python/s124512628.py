import copy
n = int(input())
s = list(input())

def search_pattern(input_list):
    temp = copy.deepcopy(input_list)
    for i in range(2, n):
        if temp[i - 1] == 'S':
            if s[i - 1] == 'o':
                temp.append(temp[i - 2])
            else:
                if temp[i - 2] == 'S':
                    temp.append('W')
                else:
                    temp.append('S')
        else:
            if s[i - 1] == 'x':
                temp.append(temp[i - 2])
            else:
                if temp[i - 2] == 'S':
                    temp.append('W')
                else:
                    temp.append('S')

    if temp[n - 1] == 'S':
        if s[n - 1] == 'o':
            if temp[n - 2] != temp[0]:
                return -1
        else:
            if temp[n - 2] == 'S':
                if temp[0] == 'S':
                    return -1
            else:
                if temp[0] != 'S':
                    return -1
    else:
        if s[n - 1] == 'x':
            if temp[n - 2] != temp[0]:
                return -1
        else:
            if temp[n - 2] == 'S':
                if temp[0] == 'S':
                    return -1
            else:
                if temp[0] != 'S':
                    return -1

    if temp[0] == 'S':
        if s[0] == 'o':
            if temp[n - 1] != temp[1]:
                return -1
        else:
            if temp[n - 1] == 'S':
                if temp[1] == 'S':
                    return -1
            else:
                if temp[1] != 'S':
                    return -1
    else:
        if s[0] == 'x':
            if temp[n - 1] != temp[1]:
                return -1
        else:
            if temp[n - 1] == 'S':
                if temp[1] == 'S':
                    return -1
            else:
                if temp[1] != 'S':
                    return -1
    print("".join(temp))
    exit()

search_pattern(list("SS"))
search_pattern(list("SW"))
search_pattern(list("WS"))
search_pattern(list("WW"))

print("-1")