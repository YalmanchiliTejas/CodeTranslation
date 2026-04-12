def main():
    N = int(input())
    A = list(map(int, input().split()))
    W = 0
    cnt = 0
    for i in range(len(A)):
        W = max(A[i],W)
        if W ==A[i]:
            cnt+=1

    print(cnt)




if __name__ == '__main__':
    main()
