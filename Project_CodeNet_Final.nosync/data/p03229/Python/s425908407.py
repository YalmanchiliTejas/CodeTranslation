def main():
    n = int(input())
    a = sorted([int(input()) for _ in range(n)])

    mid = n//2
    aa = sum(a[:mid])
    if n%2 == 0:
        ad = sum(a[mid:])
        print(2*(ad-aa)-(a[mid]-a[mid-1]))
        return 0
    ad = sum(a[mid+1:])
    tmp = min(a[mid+1]-a[mid],a[mid]-a[mid-1])
    print(2*(ad-aa)-tmp)

if __name__ == '__main__':
    main()
