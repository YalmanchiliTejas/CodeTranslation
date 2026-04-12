from string import ascii_lowercase


def main():
    str_num = int(input())
    strings = [list(input()) for _ in range(str_num)]
    answer = ""
    for lowercase in ascii_lowercase:
        count = float("inf")
        for string in strings:
            count = min(count, string.count(lowercase))
        answer += lowercase * count
    print(answer)


if __name__ == '__main__':
    main()

