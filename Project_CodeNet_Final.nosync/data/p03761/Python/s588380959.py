def main():
    n = int(input())
    from collections import Counter
    s = Counter(input())
    for i in range(1,n):
        s = s & Counter(input())
    print(''.join(sorted(s.elements())))

if __name__ == '__main__':
    main()
