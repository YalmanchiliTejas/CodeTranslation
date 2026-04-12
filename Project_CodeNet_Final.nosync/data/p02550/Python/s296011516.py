n,x,m = map(int,input().split())
mod = m
num = []
ans = 0
cnt = 0
ch = x
while True:
    if ch not in num:
        num.append(ch)
    else:
        st = ch #ループの開始している配列の初めの数字
        break
    ch *= ch
    ch %= mod
for i in range(len(num)):
    if num[i] == st:
        stnum = i #ループ開始の最初の配列のの番号
        #print("重なり始め =",stnum)
        break
else:
    stnum = len(num) - 1
if 0 in num:
    ans = sum(num[:n])
else:
    #print("len(num) =",len(num),"stnum =",stnum)
    if (len(num)-stnum) != 0:
        rest = (n-stnum)%(len(num)-stnum)
        sho = (n-stnum)//(len(num)-stnum)
        #print("rest =",rest,"sho =",sho)
    else:
        rest = n
        sho = 0
    if n <= stnum + 1:
        ans = sum(num[:n])
    else:
        ans = sum(num[:stnum]) + sum(num[stnum:stnum+rest]) + sum(num[stnum:])*sho
print(ans)