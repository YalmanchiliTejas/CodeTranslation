s=input()
i=[1 for t in  ["a","i","u","e","o"] if s==t]
print("vowel" if len(i)==1 else "consonant")