k=["a","e","i","o","u"]
c=input()
if any(c==k[i] for i in range(5)):
    print("vowel")
else:
    print("consonant")
