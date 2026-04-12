c = input()
vowels = ['a', 'i', 'u', 'e', 'o']
ans = "consonant"
for v in vowels:
    if c==v:
        ans = "vowel"
        
print(ans)