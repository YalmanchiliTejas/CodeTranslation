c  = input()

vowel = ['a', 'i', 'u', 'e', 'o']

flag = False

for i in range(5):
    if c == vowel[i]:
        flag = True
        break

if flag == True:
    print('vowel')
else:
    print('consonant')
