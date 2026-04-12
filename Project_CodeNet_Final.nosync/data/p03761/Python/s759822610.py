s = ""
dat = []
n = int(input())
for _ in range(n):
    dat.append(input())
for i in range(26):
    tch = chr(ord("a") + i)
    num = 99999
    for j in range(len(dat)):
        num = min(num, dat[j].count(tch))
    s += tch * num
print(s)
