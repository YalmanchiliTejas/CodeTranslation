def main():
    import sys
    readline = sys.stdin.buffer.readline
    readlines = sys.stdin.buffer.readlines
    
    N = int(input())
    ans = N * 800
    ans -= 200 * (N // 15)
    print(ans)


if __name__ == "__main__":
    main()
