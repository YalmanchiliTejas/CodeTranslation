# -*- coding: utf-8 -*-


def main():
    """Function."""
    c = str(input())

    cat = ["a", "e", "i", "o", "u"]
    if c in cat:
        print("vowel")
    else:
        print("consonant")


if __name__ == "__main__":
    main()
