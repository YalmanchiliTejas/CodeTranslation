n = input()
list = ['a', 'i', 'u', 'e', 'o']
judge = False

for i in list:
    if n == i:
        judge = True

if(judge):
    print('vowel')
else:
    print('consonant')
