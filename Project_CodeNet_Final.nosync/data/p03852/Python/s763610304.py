s=['a','i','o','u','e']
x=input()
falg=0
for i in s:
    if (i==x):
        falg=1
        break
if falg==0:
    print('consonant')
else:
    print("vowel")