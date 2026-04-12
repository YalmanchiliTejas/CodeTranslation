N = int(input())
s = input()

def next(previous, myself, ans):
    if myself == "S":
        if previous == "S":
            if ans == "o":
                return "S"
            else:
                return "W"
        else:
            if ans == "o":
                return "W"
            else:
                return "S"
    else:
        if previous == "S":
            if ans == "o":
                return "W"
            else:
                return "S"
        else:
            if ans == "o":
                return "S"
            else:
                return "W"


ret = "SS"
for i in range(len(s))[1:-1]:
    ret += next(ret[i - 1], ret[i], s[i])
if next(ret[-2], ret[-1], s[-1]) == ret[0] and next(ret[-1], ret[0], s[0]) == ret[1]:
    print(ret)
    quit()

ret = "SW"
for i in range(len(s))[1:-1]:
    ret += next(ret[i - 1], ret[i], s[i])
if next(ret[-2], ret[-1], s[-1]) == ret[0] and next(ret[-1], ret[0], s[0]) == ret[1]:
    print(ret)
    quit()

ret = "WS"
for i in range(len(s))[1:-1]:
    ret += next(ret[i - 1], ret[i], s[i])
if next(ret[-2], ret[-1], s[-1]) == ret[0] and next(ret[-1], ret[0], s[0]) == ret[1]:
    print(ret)
    quit()

ret = "WW"
for i in range(len(s))[1:-1]:
    ret += next(ret[i - 1], ret[i], s[i])
if next(ret[-2], ret[-1], s[-1]) == ret[0] and next(ret[-1], ret[0], s[0]) == ret[1]:
    print(ret)
    quit()

print(-1)