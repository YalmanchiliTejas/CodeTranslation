k,a,b=map(int,input().split())
if k<=a:
    print(1)
elif a-b <= 0:
    print(-1)
else:
    print(1+(k-a+(a-b)-1)//(a-b)*2)