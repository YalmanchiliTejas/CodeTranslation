N = int(input())
a = list(map(int,input().split()))

ans = [a[0]]
check = N%2==0
for i,j in enumerate(a[1:]):
    if(check):
        if(i%2==0):
            ans.insert(0,j)
        else:
            ans.append(j)
    else:
        if(i%2==1):
            ans.insert(0,j)
        else:
            ans.append(j)
print(" ".join(map(str,ans)))