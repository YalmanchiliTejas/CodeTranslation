import sys
input = sys.stdin.readline
sys.setrecursionlimit(10**6)


def main():
    a = input()
    ans = 'Yes'
    if a[0] == a[1] == a[2]:
        ans = 'No'
    print(ans)


main()
