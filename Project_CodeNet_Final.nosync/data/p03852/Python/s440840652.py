c = input()

alp = 'aiueo'

for i in range(5):
    if c == alp[i]:
        print('vowel')
        break
    if i == 4:
        print('consonant')
        break
    