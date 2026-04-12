def main():
    n = int(input())
    h = [int(n) for n in input().split()]
    ans = 0
    for i in range(n):
        for j in range(i):
            if h[j] > h[i]:
                break
        else:
            ans += 1
    print(ans)

if __name__ == '__main__':
    main()

