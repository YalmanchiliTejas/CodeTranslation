H, W = map(int, input().split())
a = []
ans = []
for i in range(H):
    a.append(input())
    
    if len(set(a[-1])) == 1 and a[-1][0] == '.':
        del a[-1]

if len(a) == 1:
    kotae = a[0]
    kotae = kotae.replace('.', '')
    print(kotae)
else:
    for x in range(W):
        check = []
        for y in range(len(a)):

            if a[y][x] != '.':
                break
            else:
                check.append(a[y][x])
                
        if len(check) == len(a):
            ans.append(x)
            
    
    if len(ans) >= 1:
        re_ans = []
        for i in a:
            kari = list(i)
            for j in ans:
                kari[j] = '0'
           # print(kari)
            re_ans.append(kari)
        
        for i in re_ans:
            moji = ''.join(i)
            mojji = moji.replace('0', '')
            print(mojji)
    else:
        for i in a:
            print(i)