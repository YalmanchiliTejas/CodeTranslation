target = input()

for v in ("a", "i", "u", "e", "o"):
    if v in target:
        print("vowel")
        exit()

print("consonant")
