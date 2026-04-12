c = input()

vowel = ['a', 'i', 'u', 'e', 'o']

for i in range (5):
    if c == vowel[i]:
        print('vowel')
        break
    if i == 4 and c != vowel[4]:
        print('consonant')
