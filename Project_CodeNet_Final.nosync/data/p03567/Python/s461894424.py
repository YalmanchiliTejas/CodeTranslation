import re


def main(s: str):
    if re.match(r'.*AC.*', s):
        print('Yes')
    else:
        print('No')


if __name__ == "__main__":
    s = input()

    main(s)
