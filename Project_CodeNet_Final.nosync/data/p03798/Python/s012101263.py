n=int(input())
s=input()
ch=['S','W']


for c1 in range(2):
    for c0 in range(2):
        if (ch[c1]=='S' and s[1]=='o') or (ch[c1]=='W' and s[1]=='x'):
            ans=ch[c0]+ch[c1]+ch[c0]
        else:
            ans=ch[c0]+ch[c1]+ch[(c0+1)%2]
        
        i=2

        while i<n-1:
            if (ans[-1]=='S' and s[i]=='o') or (ans[-1]=='W' and s[i]=='x'):
                ans+=ans[-2]
            else:
                ans+='W' if ans[-2]=='S' else 'S'
            i+=1
        
        for i in range(n):
            bc=ans[(i-1+n)%n]
            ac=ans[(i+1)%n]

            if (ans[i]=='S' and s[i]=='o') or (ans[i]=='W' and s[i]=='x'):
                if bc!=ac:
                    break
            else:
                if bc==ac:
                    break
        else:
            print(ans)
            exit(0)

print(-1)