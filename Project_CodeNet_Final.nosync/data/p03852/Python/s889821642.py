import sys
c = input()
X = "aiueo"
for i in X:
    if c == i:
        print("vowel")
        sys.exit(0)
print("consonant")