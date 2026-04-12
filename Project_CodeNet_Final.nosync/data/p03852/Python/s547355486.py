import re
a = input()

result = re.match("[aiueo]", a)
if result:
    print("vowel")
else:
    print("consonant")
