while True:
    s=raw_input()
    if s=="#":break
    cnt=0
    pre=s[0] in "qwertasdfgzxcvb"
    for c in s[1:]:
        now=c in "qwertasdfgzxcvb"
        if now<>pre:
            cnt+=1
            pre=now
    print cnt