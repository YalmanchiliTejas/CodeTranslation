a = input()
boin = False

for i in list(a):
    if i in ['a','i','u','e','o']:
        boin = True
        break

if boin:
    print("vowel")
else:
    print("consonant")