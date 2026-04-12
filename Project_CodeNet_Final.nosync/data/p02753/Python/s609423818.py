#!/usr/bin/env python3

YES = "Yes"  # type: str
NO = "No"  # type: str


def is_multi_line(S: str):
    if len(set(S)) != 1:
        return True
    else:
        return False


def main():
    S = input()  # type: str
    print(YES if is_multi_line(S) else NO)


if __name__ == '__main__':
    main()
