
def resolve():
    c = input()
    print("vowel" if c in ["a", "i", "u", "e", "o"] else "consonant")


if '__main__' == __name__:
    resolve()