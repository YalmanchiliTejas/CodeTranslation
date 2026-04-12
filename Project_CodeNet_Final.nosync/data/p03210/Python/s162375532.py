
ii = lambda : int(input())
mi = lambda : map(int,input().split())
li = lambda : list(map(int,input().split()))


def main():
    n = ii()
    if n == 3 or n == 5 or n == 7:
        print("YES")
    else:
        print("NO")


main()
