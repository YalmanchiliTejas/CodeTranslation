l=["q","w","e","r","t","a","s","d","f","g","z","x","c","v","b"]
while 1:
    s=input()
    if s=="#":break
    ans=0
    pos=0 if s[0] in l else 1
    for i in s[1:]:
        pos_n=0 if i in l else 1
        if pos!=pos_n:
            ans+=1
            pos=pos_n
    print(ans)
