c = input()
boin = ['a','i','u','e','o']
for i in c:
    if i not in boin:
        print("consonant")
        exit()

print("vowel")