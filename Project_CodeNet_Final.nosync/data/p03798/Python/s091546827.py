import sys
input = sys.stdin.readline
from itertools import product

def main():
    n = int(input())
    s = input()
    ans = "-1"

    ls = list(product("SW", repeat = 2))

    for tpl in ls:
        anss = str(tpl[0]) + str(tpl[1])
        for i in range(1,n+1):
            if anss[-1] == "S":
                if s[i-1] == "o":
                    anss += anss[-2]
                else:
                    if anss[-2] == "S":
                        anss += "W"
                    else:
                        anss += "S"
            else:
                if s[i-1] == "x":
                    anss += anss[-2]
                else:
                    if anss[-2] == "S":
                        anss += "W"
                    else:
                        anss += "S"
        if anss[:2] == anss[-2:]:
            ans = anss[1:-1]
            break
    print(ans)

if __name__ == "__main__":
    main()