import bisect


def main():
    n = int(input())
    a = [int(input()) for _ in range(n)]

    colors = [-a[0]]
    for aa in a[1:]:
        i = bisect.bisect_right(colors, -aa)
        if i == len(colors):
            colors.append(-aa)
        else:
            colors[i] = -aa
    print(len(colors))


main()
