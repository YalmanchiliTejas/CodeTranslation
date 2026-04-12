char = input()

vowels = ['a', 'i', 'u', 'e', 'o']

for vowel in vowels:
    if char == vowel:
        print("vowel")
        exit(0)

print("consonant")