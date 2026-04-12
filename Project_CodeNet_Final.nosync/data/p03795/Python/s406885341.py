# coding: utf-8
def getLnInputs():
    return input().split()


def getLnIntInputs():
    return list(map(int, getLnInputs()))


def main():
    N = getLnIntInputs()[0]
    print(800 * N - 200 * (N // 15))
    return


main()
