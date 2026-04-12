k = input()
vowels = set("aeiou")
vowels.add(k)

if len(vowels) == 6:
    print("consonant")
else:
    print("vowel")