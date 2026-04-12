def main():
    from sys import stdin

    readline = stdin.readline

    X = int(readline().rstrip())

    if X >= 30:
        print('Yes')
    else:
        print('No')
 

main()