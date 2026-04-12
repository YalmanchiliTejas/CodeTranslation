import itertools
n,m = map(int,input().split())
s = set()
for i in range(m):
    a,b = map(int,input().split())
    s.add((a,b))
    s.add((b,a))
ans = 0
#print(s)
for i in itertools.permutations(range(2,n+1)):
    genzai = 1
    #print(i)
    for j in range(len(i)):
        if (genzai,i[j]) not in s:
            break
        genzai = i[j]
    else:
        ans += 1
print(ans)