n=int(input())
a=[]
for _ in range(n):
    a.append(int(input()))
     
if n==2:
    print(abs(a[0]-a[1]))
    exit()

a=sorted(a)
turn=(n-1)//2
pre=a[0]*2
ans=0
for i in range(turn):
    if i%2==0:
        p=a[n-i-1]
        q=a[n-i-2]
        new=p+q
        ans += new-pre
        m=p-a[n-i-3]
    else:
        p=a[i]
        q=a[i+1]
        new=p+q
        ans += pre-new
        m=a[i+2]-p
    pre=new

if n%2==0:
    ans += m

a=sorted(a,reverse=True)
pre=a[0]*2
ans1=0
for i in range(turn):
    if i%2==0:
        p=a[n-i-1]
        q=a[n-i-2]
        new=p+q
        ans1 += pre-new
        m=a[n-i-3]-p
    else:
        p=a[i]
        q=a[i+1]
        new=p+q
        ans1 += new-pre
        m=p-a[i+2]
    pre=new

if n%2==0:
    ans1 += m

las=max(ans,ans1)
print(las)