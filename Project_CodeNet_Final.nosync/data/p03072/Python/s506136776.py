def main():

    N = int(input())
    H = [int(h) for h in input().split()]

    count = 1

    for n in range(1, N):
        flag = True
        for m in range(n):
            if H[m] > H[n]:
                flag = False
        if flag:
            count += 1

    print(count)


main()
