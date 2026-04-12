def solve():
    c = input()

    if c == "a":
        return True
    elif c == "e":
        return True
    elif c == "i":
        return True
    elif c == "o":
        return True
    elif c == "u":
        return True

    return False


if __name__ == '__main__':
    res = solve()

    if res:
        print("vowel")
    else:
        print("consonant")
