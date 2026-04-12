N = int(input())
S = input()
ls = ['SS','SW','WS','WW']
ok = -1
for ind,i in enumerate(S):
    if(ind==0):continue
    if(ind==N-1):break
    for indj,j in enumerate(ls):
        if(i=='o'):
            if(j[ind]=='S'):
                ls[indj] += j[ind-1]
            else:
                ls[indj] += 'W' if j[ind-1]=='S' else 'S'
        else:
            if(j[ind]=='S'):
                ls[indj] += 'W' if j[ind-1]=='S' else 'S'

            else:
                ls[indj] += j[ind-1]
for num,l in enumerate(ls):
    flag = True
    for ind,i in enumerate(S):
        if(ind==0):
            a = l[-1]
            b = l[1]
        elif(ind==N-1):
            a = l[-2]
            b = l[0]
        else:
            a = l[ind-1]
            b = l[ind+1]
        if(i=='o'):
            if(l[ind]=='S'):
                flag&=(a==b)
            else:
                flag&=(a!=b)
        else:
            if(l[ind]=='S'):
                flag&=(a!=b)
            else:
                flag&=(a==b)
        if(not flag):
            break
    if(flag):
        ok = num
        break
if(ok==-1):
    print(-1)
else:
    print(ls[ok])
