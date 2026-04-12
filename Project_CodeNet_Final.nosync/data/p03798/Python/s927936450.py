# ABC055D - Menagerie (ARC069D)
def check(a: int, b: int) -> list:
    ret, cur, prev = [], a, b
    for i in S:
        ret += [cur]
        if cur ^ (i == "o"):
            prev, cur = cur, prev ^ 1  # both are different
        else:
            prev, cur = cur, prev  # both neighbors are the same
    flg = cur == a and prev == b  # check the consistency of input and result
    return ret if flg else []


def main():
    global S
    N = int(input())
    S = input().rstrip()
    for a in range(2):
        for b in range(2):
            ans = check(a, b)
            if ans:
                print("".join("S" if i else "W" for i in ans), sep="")
                return
    print(-1)


if __name__ == "__main__":
    main()