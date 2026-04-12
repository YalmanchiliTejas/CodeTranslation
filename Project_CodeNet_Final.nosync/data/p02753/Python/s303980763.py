def main():
    S = input()
    ans = "No"
    for i in range(2):
        if (S[i] != S[i+1]):
            ans = "Yes"
    print(ans)


if __name__ == '__main__':
    main()