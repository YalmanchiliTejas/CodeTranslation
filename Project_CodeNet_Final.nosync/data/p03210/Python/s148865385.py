from sys import stdin

def main():
    X = int(input())

    if X in (3, 5, 7):
        print('YES')
    else:
        print('NO')

input = lambda: stdin.readline()
main()
