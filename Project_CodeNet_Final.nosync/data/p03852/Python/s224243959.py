c = set(input())
mother = {'a', 'i', 'u', 'e', 'o'}
print('vowel' if len(c & mother) != 0 else 'consonant')