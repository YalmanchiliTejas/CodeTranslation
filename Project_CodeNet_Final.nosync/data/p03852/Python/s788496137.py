import sys
c = str(input())
r = ["a","e","i","o","u"]
for i in range(len(r)):
    if c ==r[i]:
        print("vowel")
        sys.exit()
print("consonant")