c = input()
listc = ['a', 'e', 'i', 'o', 'u']
count = 0

for i in range(len(listc)):
    if c == listc[i]:
        count += 1
        break

if count > 0:
    print('vowel')
else:
    print('consonant')
