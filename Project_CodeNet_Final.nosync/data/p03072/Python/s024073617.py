N = int(input())
H = map(int,input().split())
tmp,res = 0,0
for i in H:
    if tmp <= i:
        res += 1
    tmp = max(tmp,i)
else:
    print(res)
