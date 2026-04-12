def main():
    n = int(input())

    l = list(map(int, input().split()))

    hh = l[0]
    cnt = 0
    
    for i in l:
        if i >= hh:
            cnt += 1
            hh = i
    
    print(cnt)

if __name__ == "__main__":
    main()
