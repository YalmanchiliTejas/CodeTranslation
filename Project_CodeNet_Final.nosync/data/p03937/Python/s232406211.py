# AGC007A - Shik and Stone
import sys
input = sys.stdin.readline

def main():
    h, w = tuple(map(int, input().rstrip().split()))
    B = tuple(input().rstrip() for _ in range(h))
    cnt = ("".join(B)).count("#")
    print("Possible" if cnt == h + w - 1 else "Impossible")


if __name__ == "__main__":
    main()