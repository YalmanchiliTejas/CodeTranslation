import sys
def input():
    return sys.stdin.readline()[:-1]

def main():
    S = input()
    if "A" not in S or "B" not in S:
        print("No")
    else:
        print("Yes")

if __name__ == "__main__":
    main()