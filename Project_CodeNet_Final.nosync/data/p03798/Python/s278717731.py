N = int(input())
s = list(input())
one_two_pair = (["S", "S"], ["S", "W"], ["W", "S"], ["W", "W"])
for one_two in one_two_pair:
    ans = one_two
    for i in range(1, N - 1):
        left = ans[i - 1]
        now = ans[i]
        ox = s[i]
        if now == "S":
            if ox == "o":
                if left == "S":
                    ans.append("S")
                else:
                    ans.append("W")
            else:
                if left == "S":
                    ans.append("W")
                else:
                    ans.append("S")
        elif now == "W":
            if ox == "o":
                if left == "S":
                    ans.append("W")
                else:
                    ans.append("S")
            else:
                if left == "S":
                    ans.append("S")
                else:
                    ans.append("W")
    first, last = False, False
    left = ans[-1]
    now = ans[0]
    right = ans[1]
    if now == "S":
        if s[0] == "o":
            first = (left == right)
        else:
            first = (left != right)
    else:
        if s[0] == "o":
            first = (left != right)
        else:
            first = (left == right)

    left = ans[-2]
    now = ans[-1]
    right = ans[0]
    if now == "S":
        if s[-1] == "o":
            last = (left == right)
        else:
            last = (left != right)
    else:
        if s[-1] == "o":
            last = (left != right)
        else:
            last = (left == right)

    if first and last:
        print("".join(ans))
        break

else:
    print(-1)
