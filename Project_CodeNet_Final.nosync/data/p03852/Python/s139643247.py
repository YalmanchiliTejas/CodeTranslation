c=input()
a='aiueo'
lst=list(a)
count=0
for i in lst:
    if c==i:
        count+=1
if count>0:
    print('vowel')
else:
    print('consonant')