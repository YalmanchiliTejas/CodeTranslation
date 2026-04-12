n,x,mod = map(int,input().split())
num = []
ans = cnt = 0
ch = x
while True:
    if ch not in num:
        num.append(ch)
    else:
        st = ch
        break
    ch *= ch
    ch %= mod

index = num.index(st)

if (len(num)-index) != 0:
    rest = (n-index)%(len(num)-index)
    qu = (n-index)//(len(num)-index)
else:
    rest = n
    qu = 0
if n <= index + 1:
    ans = sum(num[:n])
else:
    ans = sum(num[:index]) + sum(num[index:index+rest]) + sum(num[index:])*qu
print(ans)