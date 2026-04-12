def solve():
    n = int(input())
    h = list(map(int, input().split()))
    return len([True for i in range(n) if h[i] == max(h[:i + 1])])


if __name__ == "__main__":
    print(solve())
