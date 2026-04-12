def deci(c):
    vowelList = ["a", "i", "u", "e", "o"]

    for i in vowelList:
        if c == i:
            return "vowel"
    return "consonant"


print(deci(input()))
