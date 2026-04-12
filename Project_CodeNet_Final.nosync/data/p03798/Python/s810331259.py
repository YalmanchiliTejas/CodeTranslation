n = int(input())
s = input()

#ox
ans = "-1"

for animals in ["SS","SW","WS","WW"]:
    for say in s:
        if (animals[-1] == "S" and say == "o" ) or (animals[-1] == "W" and say == "x"):
            animals += animals[-2]
        elif (animals[-1] == "S" and say == "x"):
            if animals[-2] == "S":
                animals += "W"
            else:
                animals += "S"
        elif (animals[-1] == "W" and say == "o"):
            if animals[-2] == "S":
                animals += "W"
            else:
                animals += "S"
    if animals[:2] == animals[-2:]:
        ans  =animals[1:-1]
print(ans)
