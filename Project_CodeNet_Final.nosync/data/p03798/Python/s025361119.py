n = int(input())
s = input()
s = s + s[0]

inv = { "S": "W", "W": "S" }

for zero, one in [["S", "S"], ["S", "W"], ["W", "S"], ["W", "W"]]:
    animals = [zero, one]
    for i in range(2, n + 2):
        if animals[i - 1] == "S":
            if s[i - 1] == "o":
                animals.append(animals[i - 2])
            else:
                animals.append(inv[animals[i - 2]])
        else:
            if s[i - 1] == "o":
                animals.append(inv[animals[i - 2]])
            else:
                animals.append(animals[i - 2])
    if animals[0] == animals[n] and animals[1] == animals[n + 1]:
        print("".join(animals[0:n]))
        exit(0)

print(-1)
