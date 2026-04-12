from string import ascii_lowercase


def main():
    n = int(input())
    count = {a: 10 ** 9 + 7 for a in ascii_lowercase}
    for _ in range(n):
        s = input()
        for a in ascii_lowercase:
            count[a] = min(count[a], s.count(a))
    answer = []
    for a in ascii_lowercase:
        if 10 ** 9 + 7 > count[a]:
            for _ in range(count[a]):
                answer.append(a)
    answer.sort()
    print("".join(answer))


if __name__ == '__main__':
    main()

