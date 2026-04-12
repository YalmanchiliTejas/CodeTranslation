c = input()

result = "consonant"
vowel = ["a","e","i","o","u"]

for i in vowel:
    if i == c:
        result = "vowel"
        break

print(result)
