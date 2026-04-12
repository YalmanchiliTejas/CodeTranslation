def solve():
    n = int(input())
    s = list(input())
    k = int(input())
    tar = s[k-1]
    for i in range(n):
        if s[i] != tar:
            s[i] = "*"
    print("".join(s))
    return 0

if __name__ == "__main__":
    solve()
