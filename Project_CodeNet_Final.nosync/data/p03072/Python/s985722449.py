import sys

if __name__ == '__main__':
    N = int(sys.stdin.readline())
    H = list(map(lambda x: int(x), sys.stdin.readline().split(' ')))
    ans = 0

    for i in range(N):
        for j in range(i):
            if H[i] < H[j]:
                break
        else:
            ans += 1
    print(ans)