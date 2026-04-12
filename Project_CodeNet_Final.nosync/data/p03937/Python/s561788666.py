import sys
input=sys.stdin.readline

def main():
    H,_ = map(int, input().split())
    a = input().strip()
    for _ in range(H-1):
        b = input().strip()
        if a.rfind("#") > b.find("#"):
            print("Impossible")
            return
        a = b
    print("Possible")

if __name__ == '__main__':
    main()
