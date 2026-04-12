def resolve():
    import sys

    input = sys.stdin.readline




    s = input().rstrip()

    print("No" if s == "AAA" or s == "BBB" else "Yes")

resolve()