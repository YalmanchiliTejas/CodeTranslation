def main():
    N = int(input())
    H = list(map(int, input().split()))

    count = 0
    m = 0
    for h in H:
        if m <= h:
            count += 1
            m = h

    print(count)

main()