def main():
    N = int(input())
    li = list(map(int,input().split()))
    count = 0
    for i in range(len(li)):
        if(max(li[:i+1])==li[i]):
            count += 1

    print(count)

if __name__ == '__main__':
    main()
