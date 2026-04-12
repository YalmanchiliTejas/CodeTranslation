n,x,m = map(int,input().split())
set_ = set()
l = []
cnt =0
dic = {}
while x not in set_ and cnt<n:
    set_.add(x)
    l.append(x)
    dic[x]= cnt
    cnt += 1
    x = (x**2)%m
    if x==0:
        l.append(0)
        break
if l[-1]==0:
    print(sum(l));exit()
if cnt==n:
    print(sum(l));exit()

ans = sum(l[:dic[x]])
l = l[dic[x]:]

L = l+ l
cnt  = len(l)
n-=dic[x]
s = sum(l)
ans += (n//cnt)*s + sum(l[:n%cnt])

print(ans)