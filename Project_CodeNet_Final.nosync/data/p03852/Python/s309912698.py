s = input()

if any([True if s == x else False for x in ['a', 'e', 'i', 'o', 'u']]):
    print('vowel')
else:
    print('consonant')