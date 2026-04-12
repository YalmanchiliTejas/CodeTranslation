a=list(map(int,input().split()))
ans=a[0]*100+a[1]*10+a[2]
if ans%4==0:
    print("YES")
else:
    print("NO")