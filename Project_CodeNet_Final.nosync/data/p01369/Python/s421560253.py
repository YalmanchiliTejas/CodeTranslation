l = ['qwertasdfgzxcvb','yuiophjklnm']
while True:
    s = list(input())
    if s[0]=='#': break
    c,k = 0, 0 if s[0] in l[0] else 1
    for x in s:
        if not(x in l[k]):
            c += 1
            k = abs(k-1)
    print(c)