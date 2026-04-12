import sys
input = sys.stdin.readline

def main():
    s = input()
    if s.count(s[0]) != 3:
        print("Yes")
    else:
        print("No")


main()