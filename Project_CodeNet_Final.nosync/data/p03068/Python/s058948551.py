def main():
    n = int(input())
    s = list(input())
    k = int(input()) - 1
    for i in range(n):
        if s[i] != s[k]:
            s[i] = '*'
    print("".join(s))
    return 0

main()