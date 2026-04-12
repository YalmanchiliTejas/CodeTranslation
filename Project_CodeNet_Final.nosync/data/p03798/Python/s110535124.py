# ABC055D - Menagerie (ARC069D)
def check(a: str, b: str) -> str:
    ret, cur, prev = "", a, b
    for i in S:
        ret += cur
        if (cur == "S" and i == "o") or (cur == "W" and i == "x"):
            prev, cur = cur, prev  # both neighbors are the same
        elif (cur == "S" and i == "x") or (cur == "W" and i == "o"):
            x = "W" if prev == "S" else "S"  # both are different
            prev, cur = cur, x
    flg = cur == a and prev == b  # check the consistency of input and result
    return ret if flg else ""


def main():
    global S
    N = int(input())
    S = input().rstrip()
    for a in ("S", "W"):
        for b in ("S", "W"):
            ans = check(a, b)
            if ans:
                print(ans)
                return
    print(-1)


if __name__ == "__main__":
    main()