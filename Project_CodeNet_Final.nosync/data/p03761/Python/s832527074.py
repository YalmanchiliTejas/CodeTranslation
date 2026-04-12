n = int(input())
import string
characters = list(string.ascii_lowercase)
lettercount = dict()
for character in characters :
    lettercount[character] = []
for i in range(n) :
    si = input()
    for character in characters :
        lettercount[character] += [si.count(character)] 
for character in characters :
    lettercount[character] = min(lettercount[character])
lettercount = sorted(list(lettercount.items()), key = lambda x : x[0])
ans = ""
for lettertuple in lettercount :
    ans += lettertuple[0] * lettertuple[1]
print(ans)