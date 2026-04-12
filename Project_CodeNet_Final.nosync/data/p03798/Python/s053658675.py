N = int(input())
s = input()

def SorW(i, now, pre):
    if s[i] == "o":
        if now == "S":
            return pre
        elif now == "W":
            return ("S" if pre == "W" else "W")
    elif s[i] == "x":
        if now == "S":
            return ("S" if pre == "W" else "W")
        elif now == "W":
            return pre

if s[0] == "o":
    Ini = ["SSS", "WSW", "SWW", "WWS"]
else:
    Ini = ["SSW", "WSS", "SWS", "WWW"]

for start in Ini:
    pre, now = start[1], start[2]
    ans, i = pre + now, 1
    while i <= N-1:
        next = SorW(i, now, pre)
        now, pre = next, now
        i += 1
        ans += next
    if start[1] == now and start[0] == pre:
        print(ans[:-1])
        break
else:
    print(-1)