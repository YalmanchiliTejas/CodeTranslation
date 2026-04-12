def main():
    n = int(input())
    from collections import Counter
    c = Counter(input())
    for i in range(1,n):
        c = c & Counter(input())
    print(''.join(sorted(c.elements())))

if __name__ == '__main__':
    main()

