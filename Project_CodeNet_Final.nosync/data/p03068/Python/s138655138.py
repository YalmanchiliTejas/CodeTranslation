def main():
    N = int(input())
    S = input()
    K = int(input())
    t = S[K-1]
    result = ""
    for s in S:
        if s == t:
            result += s
        else:
            result += "*"
    print(result)

if __name__ == '__main__':
    main()