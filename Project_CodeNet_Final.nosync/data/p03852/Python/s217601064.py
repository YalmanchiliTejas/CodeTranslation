c = input().rstrip()

vowels = ['a','e','i','o','u']

for idx,i in enumerate(vowels):
    if c == i:
        print("vowel")
        break
    elif idx < 4:
        pass
    else:
        print("consonant")