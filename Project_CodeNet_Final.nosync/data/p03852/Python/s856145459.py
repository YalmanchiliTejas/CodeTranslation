s1=input()
count=0
l=["a","i","u","e","o"]
for w in l:
    if s1==w:
        print("vowel")
        count=count+1
if count==0:
    print("consonant")
