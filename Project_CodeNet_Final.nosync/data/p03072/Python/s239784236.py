import sys
input=sys.stdin.readline
#input = open(sys.argv[1], "r").readline

def main():
    _ = int(input())
    H = list(map(int, input().split()))
    n = 0
    for i in range(len(H)):
        b = True
        for j in range(0,i):
            if H[i] < H[j]:
                b = False
                break
        if b:
            n += 1
    print(n)

if __name__ == '__main__':
    main()
