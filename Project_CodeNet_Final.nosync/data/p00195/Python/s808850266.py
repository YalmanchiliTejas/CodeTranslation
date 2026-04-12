L=["A","B","C","D","E"]
while True:
    dic={}
    for c in L:
        s1,s2=map(int,raw_input().split())
        if s1==s2==0:break
        dic[s1+s2]=c
    if s1==s2==0:break
    m=max(dic)
    print dic[m],m