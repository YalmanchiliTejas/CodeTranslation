import sys

if __name__ == '__main__':
    H, W = (int(i) for i in input().split())
    arr = input()
    index = arr.rfind("#")
    for i in range(H-1):
        arr = input()
        if arr.find("#") != index:
            print("Impossible")
            sys.exit()

        if arr.rfind("#") == (W - 1) and index == (W - 1) and arr.find("#") != (W - 1):
            print("Impossible")
            sys.exit()

        index = arr.rfind("#")

    print("Possible")
