r='yuiophjklnm'
while 1:
    s,c=input(),0
    if s=='#':break
    f='r' if s[0] in r else 'l'
    for i in s:
        if i in r:
            if f=='l':c+=1
            f='r'
        else:
            if f=='r':c+=1
            f='l'
    print(c)