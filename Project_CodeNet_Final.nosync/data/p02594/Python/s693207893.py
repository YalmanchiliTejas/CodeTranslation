from sys import stdin


def main():
    input = lambda: stdin.readline()[:-1]
    X = int(input())
    if X >= 30:
        print("Yes")
    else:
        print("No")


main()
