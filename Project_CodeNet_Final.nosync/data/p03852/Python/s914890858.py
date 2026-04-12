# coding: utf-8

boinboin=('a','i','u','e','o')

tmp=input()
flg=False

for i in range(len(boinboin)):
    if boinboin[i]==tmp:
        flg=True
if flg==True:
    print('vowel')
else:
    print('consonant')