import sys
N = int(input())
s = input()

lst = ["SW", "WS", "SS", "WW"]
ans = []

for tmp in lst:
    for i in range(1, N-1):
        if(s[i] == "o"):
            if(tmp[i] == "S"):
                tmp += tmp[i-1]
            else:
                if(tmp[i-1] == "S"):
                    tmp += "W"
                else:
                    tmp += "S"
        else:
            if(tmp[i] == "W"):
                tmp += tmp[i-1]
            else:
                if(tmp[i-1] == "S"):
                    tmp += "W"
                else:
                    tmp += "S"

    ans.append(tmp)

for st in ans:
    flg = True
    if(s[0] == "o"):
        if(st[0] == "S"):
            if(st[-1] != st[1]):
                flg = False
        else:
            if(st[-1] == st[1]):
                flg = False
    else:
        if(st[0] == "S"):
            if(st[-1] == st[1]):
                flg = False
        else:
            if(st[-1] != st[1]):
                flg = False
    if(s[N-1] == "o"):
        if(st[N-1] == "S"):
            if(st[N-2] != st[0]):
                flg = False
        else:
            if(st[N-2] == st[0]):
                flg = False
    else:
        if(st[N-1] == "S"):
            if(st[N-2] == st[0]):
                flg = False
        else:
            if(st[N-2] != st[0]):
                flg = False
    if(flg):
        print(st)
        sys.exit()
print(-1)      