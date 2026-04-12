def main():
    N = int(input())
    m = 0
    h = [int(x) for x in input().split()]
    count = 0
    
    for i in h:
        if m <= i:
            count += 1
            m = i
    
    print(count)

if __name__ == '__main__':
    main()