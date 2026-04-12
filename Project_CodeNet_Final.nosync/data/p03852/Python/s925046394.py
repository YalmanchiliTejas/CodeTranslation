def actual(c):
    if c in list('aeiou'):
        return 'vowel'

    return 'consonant'

c = input()
print(actual(c))