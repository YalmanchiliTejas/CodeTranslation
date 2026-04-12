def main():
    N = int(input())
    *H, = map(int, input().split())
    count = 0
    for i in range(len(H)):
        if H[i] == max(H[:i + 1]):
            count += 1
    print(count)

main()
