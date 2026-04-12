def main():
    N = int(input())
    H = [int(h) for h in input().split()]
    max_h = 0
    count = 0
    for i in range(N):
        if H[i] >= max_h:
            count += 1
        max_h = max(max_h, H[i])
    return count

if __name__ == '__main__':
    print(main())