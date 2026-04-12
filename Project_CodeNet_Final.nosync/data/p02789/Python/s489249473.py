def main():
    import sys
    sys.setrecursionlimit(10**9)
    input = sys.stdin.readline

    n, m = map(int, input().split())
    if n==m:
        print("Yes")
    else:
        print("No")

main()