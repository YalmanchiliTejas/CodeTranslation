# coding: utf-8
def main():
    n = int(input())
    s = list(input())
    k = int(input())

    c = s[k-1]
    for i, _ in enumerate(s):
        s[i] = "*" if s[i] != c else s[i]

    return "".join(s)


print(main())