n=int(input())
ans=[]

for i in range(n):
    s=input()
    s=list(s)
    if i == 0:
        ans=s
    else:
        memo=[]
        for l in s:
            if l in ans:
                indexnumber = ans.index(l)
                p = ans.pop(indexnumber)
                memo.append(p)  
        ans=memo

ans.sort()
print(''.join(map(str,ans)))