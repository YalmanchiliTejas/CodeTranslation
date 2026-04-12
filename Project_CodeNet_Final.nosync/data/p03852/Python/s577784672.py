c = str(input())

vow = ['a','i','u','e','o']
flag = 0

for i in vow:
    if c == i:
        print('vowel')
        
    else:
        flag+=1
        
if flag ==5:
    print('consonant')