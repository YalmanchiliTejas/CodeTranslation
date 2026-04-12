n = int(input())
s = input()
k = int(input())

sk = s[k-1]

ans = []

for si in s:
    if si == sk:
        ans.append(si)
    else:
        ans.append("*")
        
print(*ans,sep="")
