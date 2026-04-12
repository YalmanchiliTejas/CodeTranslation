def main():
    n = int(input())
    s = input().rstrip()
    k = int(input()) 
    l = s[k-1]
    char_array = [None] * n
    for i, c in enumerate(s):
        if c != l:
            char_array[i] = '*'
        else:
            char_array[i] = l
    print(''.join(char_array))


if __name__ == "__main__":
    main()