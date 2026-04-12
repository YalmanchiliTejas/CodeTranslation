n, x = map(int, input().split())

a = [1]
p = [1]
so_num = 1
for i in range(1, 51):
    a.append(a[i-1] * 2 + 3)
    p.append(p[i-1] * 2 + 1)

#print(a)
#print(p)

ans = 0
lv = n
tmp =x
while lv >= 0:
    z = (a[lv]-1)//2
    #print('lv,tmp,z,ans: ',lv, tmp, z, ans)
    if lv == 0:
        if tmp >= 1:
            ans += 1
        break
    if tmp > z:
        ans += p[lv - 1] + 1
        tmp = tmp - z - 1
        lv -= 1
    elif tmp == z:
        ans += p[lv - 1]
        break
    else:
        tmp -= 1
        lv -= 1
        # ans 何もしない
    
print(ans)