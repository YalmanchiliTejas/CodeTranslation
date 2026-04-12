n = int(input())
s = input()
ans = ["SS","SW","WS","WW"]
for a in ans:
    for i in range(2,n+1):
        if s[i-1] == "o":
            if a[-2:] == "SS" or a[-2:] == "WW":
                a += "S"
            else:
                a += "W"
        if s[i-1] == "x":
            if a[-2:] == "SW" or a[-2:] == "WS":
                a += "S"
            else:
                a += "W"
    else:
        if a[n] == a[0]:
            if (((s[0],a[0]) in (("o","S"),("x","W")) and a[1] == a[n-1])
                or ((s[0],a[0]) in (("x","S"),("o","W")) and a[1] != a[n-1])):
                print(a[:n])
                exit()
print(-1)
