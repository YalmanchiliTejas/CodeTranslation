def main():
    H, W = list(map(int, input().split(" ")))
    a = []
    for r in range(H):
        a += [input()]
    output = solve(H, W, a)
    for s in output:
        print(s)
    return

#________________________________________
#  Solve
#________________________________________
def solve(H, W, a):
    """
    解答のコード
    """
    index_list = []
    for _r in range(H):
        for _c in range(W):
            if a[_r][_c] is not ".":
                break
            if _c == W-1:
                index_list += [_r]
    j = 0
    for i in index_list:
        del a[i-j]
        j += 1

    index_list = []
    a = list(map(list, zip(*a)))
    for _r in range(len(a)):
        for _c in range(len(a[0])):
            if a[_r][_c] is not ".":
                break
            if _c == len(a[0])-1:
                index_list += [_r]
    j = 0
    for i in index_list:
        del a[i-j]
        j += 1
    a = list(map(list, zip(*a)))
    a = [ "".join(a[i]) for i in range(len(a))]
    return a
#________________________________________


if __name__ == "__main__":
    main()