c = set(input())
s = {"a","i","u","e","o"}
w = c|s
if len(w) == 5 :
    print("vowel")
else:
    print("consonant")