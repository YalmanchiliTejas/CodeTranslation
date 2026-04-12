while True:
    st = list(input().split("/"))
    if st == ["#"]:
        break
    a, b, c, d = map(int, input().split())

    s=[]
    for i in range(len(st)):
        str=[]
        for ele in st[i]:
            if ele=="b":
                str.append("b")
            else:
                for _ in range(int(ele)):
                    str.append(".")
        s.append(str)

    s[a-1][b-1] = "."
    s[c-1][d-1] = "b"

    '''
    print(s)
    ans=""
    for i in range(len(s)):
        count = 0
        for ele in s[i]:
            if ele=="b":
                sr="{}".format(count)
                ans=ans+sr
                ans+="b"
            else:
                count+=1
        ans+="/"
    print(ans)
    '''


    ans = []
    for i in range(len(s)):
        sr = ""
        c = 0
        for j in range(len(s[i])):
            if s[i][j] == 'b':
                if c != 0:
                    sr += "{}".format(c)
                sr += "b"
                c=0
            elif s[i][j] == '.':
                c += 1
            '''
            if j==len(s[i])-1:
                if s[i][j] == '.' and c != 0:
                    sr += "{}".format(c)
            '''
        if c!=0:
            sr+="{}".format(c)
        ans.append(sr)
    ass = "/".join(ans)
    print(ass[:])

