c=input()

vowel=['a', 'e', 'i', 'o', 'u']
ans='consonant'
for s in vowel:
    if s is c:
        ans='vowel'
    else: ans=ans
       
    
print(ans)