def main():
    N = int(input())
    H = list(map(int, input().split()))
    Highest = 0
    ac = 0
    for i in range(N):
        if Highest <= H[i]:
            ac += 1
            Highest = H[i]
    print(ac)
main()

