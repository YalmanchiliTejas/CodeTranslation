# -*- coding: utf-8 -*-

c = input()

bo = ['a','e','i','o','u']

check = 0
for i in bo:
    if c == i:
        print("vowel")
        check = 1
        break
    else:
        pass

if check == 0:
    print("consonant")
else:
    pass