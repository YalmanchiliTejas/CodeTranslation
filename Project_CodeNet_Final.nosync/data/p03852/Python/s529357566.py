import sys
c=input()
List=["a","i","u","e","o"]
for i in List:
    if i==c:
        print("vowel")
        sys.exit()
print("consonant")