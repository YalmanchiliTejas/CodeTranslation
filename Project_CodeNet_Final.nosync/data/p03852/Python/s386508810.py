c = input()
vowellist = ["a","i","u","e","o"]
judge = "a"
for w in vowellist:
    if c == w:
        judge = "vowel"
        break
    else:
        judge = "consonant"
print(judge)
