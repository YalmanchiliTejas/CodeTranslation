def main():

    N = int(input())
    s = input()
    if s[0] == "o":
        cand = [["S", "S", "S"], ["W", "S", "W"], ["W", "W", "S"], ["S", "W", "W"]]
    else:
        cand = [["S", "S", "W"], ["W", "S", "S"], ["W", "W", "W"], ["S", "W", "S"]]

    for cd in cand:
        for i in range(1, N):
            if s[i] == "o" and cd[-1] == "S":
                if cd[-2] == "S": cd.append("S")
                else: cd.append("W")
            elif s[i] == "x" and cd[-1] == "S":
                if cd[-2] == "S": cd.append("W")
                else: cd.append("S")
            elif s[i] == "o" and cd[-1] == "W":
                if cd[-2] == "S": cd.append("W")
                else: cd.append("S")
            elif s[i] == "x" and cd[-1] == "W":
                if cd[-2] == "S": cd.append("S")
                else: cd.append("W")
        # print(cd)
        if cd[:2] == cd[-2:]:
            return "".join(cd[1:-1])
    return -1

if __name__ == '__main__':
    print(main())