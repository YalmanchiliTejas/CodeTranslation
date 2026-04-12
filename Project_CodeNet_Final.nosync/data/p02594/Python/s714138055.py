from sys import stdin

def main():

    input = stdin.readline

    N = int(input())

    if N >= 30:
        print("Yes")
    else:
        print("No")

if __name__ == "__main__":
    main()
    