c = input() 

if (c == 'a'): 
    is_vowel = True
elif (c == 'i'):
    is_vowel = True
elif (c == 'u'):
    is_vowel = True
elif (c == 'e'):
    is_vowel = True
elif (c == 'o'): 
    is_vowel = True
else:
    is_vowel = False

if is_vowel:
    print('vowel')
else:
    print('consonant')