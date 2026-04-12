# 2019/07/09
# AtCoder Beginner Contest 058 - C

# Init
clist = ["a","b","c","d","e","f","g","h","i","j","k","l","m","n","o","p","q","r","s","t","u","v","w","x","y","z"]
sdict = dict()

for i in range(len(clist)):
    sdict[clist[i]] = 51

# Input
n = int(input())
for i in range(n):
    s = input()
    for j in range(len(clist)):
        ccnt = 0
        for k in range(len(s)):
            if clist[j] == s[k]:
                ccnt += 1
        sdict[clist[j]] = min(sdict[clist[j]], ccnt)

# Make string
ans = ""
for i in range(len(clist)):
    for j in range(sdict[clist[i]]):
        ans = ans + clist[i]

# Output
print(ans)

    