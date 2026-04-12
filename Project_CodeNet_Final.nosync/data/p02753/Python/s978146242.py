from sys import stdin


def main():
    input = lambda: stdin.readline()[:-1]
    S = input()
    if len(set(S)) == 1:
        print('No')
    else:
        print('Yes')



main()
