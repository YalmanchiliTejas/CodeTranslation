def lr(c):
    # left return 0, right return 1
    if (
        c == "p"
        or c == "l"
        or c == "o"
        or c == "k"
        or c == "m"
        or c == "i"
        or c == "j"
        or c == "n"
        or c == "u"
        or c == "y"
        or c == "h"
    ):
        return 1
    else:
        return 0


while True:
    S = input()
    change = 0
    if S == "#":
        break
    maenote = lr(S[0])
    for i in range(1, len(S)):
        if not maenote == lr(S[i]):
            change += 1
        maenote = lr(S[i])
    print(change)
