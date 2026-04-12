def main():
    length = int(input())
    string = list(input())
    index = int(input())
    not_replace = string[index - 1]
    for i in range(length):
        if string[i] != not_replace:
            string[i] = "*"
    print("".join(string))


if __name__ == '__main__':
    main()

