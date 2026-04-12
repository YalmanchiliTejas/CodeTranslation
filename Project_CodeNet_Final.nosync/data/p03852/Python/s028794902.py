c = input()
v = ["a", "e", "i", "o", "u"]

if(any(i == c for i in v)):
    print("vowel")
else:
    print("consonant")