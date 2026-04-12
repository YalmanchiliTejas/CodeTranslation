import sys
import queue


def input():
    return sys.stdin.readline().strip()


sys.setrecursionlimit(20000000)

MOD = 10 ** 9 + 7


def main():
    N = int(input())
    s = input()
    Animal = ["WW", "WS", "SS", "SW"]
    for i in range(1, N - 1):
        if s[i] == "o":
            for j in range(4):
                if Animal[j][-1] == "S":
                    Animal[j] = Animal[j] + Animal[j][-2]
                else:
                    if Animal[j][-2] == "S":
                        Animal[j] = Animal[j] + "W"
                    else:
                        Animal[j] = Animal[j] + "S"
        else:
            for j in range(4):
                if Animal[j][-1] == "S":
                    if Animal[j][-2] == "S":
                        Animal[j] = Animal[j] + "W"
                    else:
                        Animal[j] = Animal[j] + "S"
                else:
                    Animal[j] = Animal[j] + Animal[j][-2]
    for i in range(4):
        animal = Animal[i]
        if s[-1] + s[0] == "xo":
            for a in ["WWWS", "WSSS", "SWSW", "SSWW"]:
                if animal[-2:] + animal[:2] == a:
                    print(animal)
                    return
            else:
                continue

        elif s[-1] + s[0] == "xx":
            for a in ["WWWW", "WSSW", "SWSS", "SSWS"]:
                if animal[-2:] + animal[:2] == a:
                    print(animal)
                    return
                else:
                    continue

        elif s[-1] + s[0] == "ox":
            for a in ["WWSS", "WSWS", "SSSW", "SWWW"]:
                if animal[-2:] + animal[:2] == a:
                    print(animal)
                    return
        elif s[-1] + s[0] == "oo":
            for a in ["WWSW", "WSWW", "SSSS", "SWWS"]:
                if animal[-2:] + animal[:2] == a:
                    print(animal)
                    return
                else:
                    continue
    print(-1)


if __name__ == "__main__":
    main()
