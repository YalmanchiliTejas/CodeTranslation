import sys
input = sys.stdin.readline

def main():
    H, W = map(int, input().split())
    count = 0
    for _ in range(H):
        for row in list(input().rstrip()):
            count += row.count("#")
    if count == H + W - 1:
        print("Possible")
    else:
        print("Impossible")

if __name__ == '__main__':
    main()