import sys
def input(): return sys.stdin.readline().strip()

def main():
    n = int(input())
    x = 800 * n
    y = 200 * (n // 15)
    print(x - y)
    

if __name__ == "__main__":
    main()
