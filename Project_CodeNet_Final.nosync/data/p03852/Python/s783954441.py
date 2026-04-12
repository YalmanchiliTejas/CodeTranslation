import sys

arr_v = ['a','e','i','o','u']
c = input()

for v in arr_v:
    if v == c:
        print("vowel")
        sys.exit()

print("consonant")