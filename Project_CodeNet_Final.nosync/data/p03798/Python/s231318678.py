n=int(input())
s=list(input())

def rev(x):
    if x=="S":
        return "W"
    else:
        return "S"

def wolfsheep(xy):
    global n,s
    result=[xy[0],xy[1]]

    for i in range(1,n+1):
        s+=s[0]
        if result[i]=="S":
            if s[i]=="o":
                result.append(result[i-1])
            else:
                result.append(rev(result[i-1]))
        else:
            if s[i]=="o":
                result.append(rev(result[i-1]))
            else:
                result.append(result[i-1])

    if result[0]==result[n] and result[1]==result[n+1]:
        return result
    else:
        return 0

#SWパターン
tmp= wolfsheep("SW")
if tmp!=0:
    print("".join(tmp[:-2]))
    exit()

#SSパターン
tmp= wolfsheep("SS")
if tmp!=0:
    print("".join(tmp[:-2]))
    exit()
#WWパターン
tmp= wolfsheep("WW")
if tmp!=0:
    print("".join(tmp[:-2]))
    exit()
#WSパターン
tmp= wolfsheep("WS")
if tmp!=0:
    print("".join(tmp[:-2]))
    exit()

print(-1)