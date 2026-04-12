#! usr/bin/env python
# -*- coding: utf-8 -*-


def main():
    S = input()

    for i in range(len(S)-1):
        if S[i] == "A" and S[i+1] == "C":
            print("Yes")
            exit()

    print("No")


if __name__ == '__main__':
    main()
