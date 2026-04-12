l = "qwertasdfgzxcvb"
r = "yuiophjklnm"
while True:
    s=input()
    if(s=='#') : break
    a = 0
    f = '0'
    for i in range(len(s)):
        if(s[i] in l):
            if(f!='l'):
                f='l'
                a+=1
        else:
            if(f!='r'):
                f='r'
                a+=1
    print(a-1)

