import sys
def input(): return sys.stdin.readline().strip()

def main():
    r, g, b = map(int, input().split())
    n = 10 * g + b
    if n % 4 == 0:
        print("YES")
    else:
        print("NO")

if __name__ == "__main__":
    main()
