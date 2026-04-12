import sys

input = sys.stdin.readline

def main():
    ans = []
    A, B, C, X, Y = map(int, input().split())
    for i in range(10**5+1):
        ans.append((C*2*i) + (A*max(0, X-i)) + (B*max(0, Y-i)))

    print(min(ans))

if __name__ == '__main__':
    main()