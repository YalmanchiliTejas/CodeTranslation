def main():
    N = int(input())
    S = input()
    K = int(input())
    replace_char = S[K-1]
    ans = []
    for s in S:
        if s == replace_char:
            ans.append(replace_char)
        else:
            ans.append('*')
    print("".join(ans))

if __name__ == "__main__":
    main()
    