n = int(input())
s = input()
s += s[0]
pat = ["WW","WS","SW","SS"]

for j in pat:
    now = j
    flag = True
    for i in range(1,n+1):
        if (now[i] == "S" and s[i] == "o") or (now[i] == "W" and s[i] == "x"):
            now += now[i-1]
        else:
            if now[i-1] == "S":
                now += "W"
            else:
                now += "S"
    if now[0] == now[-2] and now[1] == now[-1]:
        print(now[:-2])
        exit()

print(-1)