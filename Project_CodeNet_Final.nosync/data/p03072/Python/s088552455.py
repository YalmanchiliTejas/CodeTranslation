import sys
input = sys.stdin.readline

def main():
    N = int(input())
    H = [int(x) for x in input().split()]

    m = H[0]
    ans = 1
    for i in range(1, N):
        if H[i] >= m:
            ans += 1
        m = max(m, H[i])

    print(ans)
    

if __name__ == '__main__':
    main()

