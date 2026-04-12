import sys

if __name__ == "__main__":
    S = input()

    ans = S.count("A")
    if ans == 3 or ans == 0:
        print("No")
    else:
        print("Yes")