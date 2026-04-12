def main():
    お寿司, 食べたい = map(int, input().split())
    築地 = [[] for _ in range(お寿司)]
    for _ in range(食べたい):
        鮪, 蛸 = map(lambda x: int(x) - 1, input().split())
        築地[鮪].append(蛸)
        築地[蛸].append(鮪)

    やってるかい = [False] * お寿司
    寿司くいねぇ = おなかすいた(0, 築地, やってるかい, 0)

    print(寿司くいねぇ)


def おなかすいた(市場, 築地, やってるかい, お勘定):
    やってるかい[市場] = True
    if all(やってるかい):
        return お勘定 + 1

    for 豪遊 in 築地[市場]:
        if やってるかい[豪遊]:
            continue
        お勘定 = おなかすいた(豪遊, 築地, やってるかい, お勘定)
        やってるかい[豪遊] = False

    return お勘定


if __name__ == '__main__':
    main()
