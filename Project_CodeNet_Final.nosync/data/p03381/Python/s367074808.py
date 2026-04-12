# ARC095C - Many Medians (ABC094C)
def main():
    n = int(input())
    x = tuple(map(int, input().rstrip().split()))
    l, h = sorted(x)[n // 2 - 1 : n // 2 + 1]
    for i in x:
        print(h if i <= l else l)

if __name__ == "__main__":
    main()