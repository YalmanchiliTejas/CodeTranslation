n=int(input())
s=input()

def sw(animal,maeanimal,flag):
    if animal == "S":
        if maeanimal == "S":
            if flag == "o":
                return "S"
            else:
                return "W"
        else:
            if flag == "o":
                return "W"
            else:
                return "S"
    else:
        if maeanimal == "S":
            if flag == "o":
                return "W"
            else:
                return "S"
        else:
            if flag == "o":
                return "S"
            else:
                return "W"
def main():
    r = ["" for _ in range(n)]
    r[0] = "S"
    if s[0] == "o":
        r[1] = "S"
        r[-1]= "S"
    else:
        r[1] = "S"
        r[-1] = "W"

    for i in range(1,n-2):
        r[i+1] = sw(r[i],r[i-1],s[i])
    if r[n-1] == sw(r[n-2],r[n-3],s[n-2]) and r[0] == sw(r[n-1],r[n-2],s[n-1]):
        return "".join(map(str, r))

    r = ["" for _ in range(n)]
    r[0] = "S"
    if s[0] == "o":
        r[1] = "W"
        r[-1]= "W"
    else:
        r[1] = "W"
        r[-1] = "S"

    for i in range(1,n-2):
        r[i+1] = sw(r[i],r[i-1],s[i])
    if r[n-1] == sw(r[n-2],r[n-3],s[n-2]) and r[0] == sw(r[n-1],r[n-2],s[n-1]):
        return "".join(map(str, r))

    r = ["" for _ in range(n)]
    r[0] = "W"
    if s[0] == "o":
        r[1] = "S"
        r[-1]= "W"
    else:
        r[1] = "S"
        r[-1] = "S"

    for i in range(1,n-2):
        r[i+1] = sw(r[i],r[i-1],s[i])
    if r[n-1] == sw(r[n-2],r[n-3],s[n-2]) and r[0] == sw(r[n-1],r[n-2],s[n-1]):
        return "".join(map(str, r))

    r = ["" for _ in range(n)]
    r[0] = "W"
    if s[0] == "o":
        r[1] = "W"
        r[-1]= "S"
    else:
        r[1] = "W"
        r[-1] = "W"

    for i in range(1,n-2):
        r[i+1] = sw(r[i],r[i-1],s[i])
    if r[n-1] == sw(r[n-2],r[n-3],s[n-2]) and r[0] == sw(r[n-1],r[n-2],s[n-1]):
        return "".join(map(str, r))

    return "-1"

print(main())