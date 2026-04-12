n=int(input())
s=list(input())

a=[0]*n

for i in range(n):
    if s[i]=="o":
        a[i]=1
    else:
        a[i]=-1

ans=[0]*n

flag=-1
S=["0"]*n

ans[0]=1
ans[1]=1

for i in range(2,n):
    ans[i]=a[i-1]*ans[i-1]*ans[i-2]
else:
    c1=a[0]*ans[0]*ans[n-1]
    c2=a[n-1]*ans[n-1]*ans[n-2]
    if c1==ans[1] and c2==ans[0]:
        flag=1
        for i in range(n):
            if ans[i]==1:
                S[i]="S"
            else:
                S[i]="W"
        print(''.join(S))

if flag<0:

    ans[0]=-1
    ans[1]=1

    for i in range(2,n):
        ans[i]=a[i-1]*ans[i-1]*ans[i-2]
    else:
        c1=a[0]*ans[0]*ans[n-1]
        c2=a[n-1]*ans[n-1]*ans[n-2]
        if c1==ans[1] and c2==ans[0]:
            flag=1
            for i in range(n):
                if ans[i]==1:
                    S[i]="S"
                else:
                    S[i]="W"
            print(''.join(S))

if flag<0:

    ans[0]=1
    ans[1]=-1

    for i in range(2,n):
        ans[i]=a[i-1]*ans[i-1]*ans[i-2]
    else:
        c1=a[0]*ans[0]*ans[n-1]
        c2=a[n-1]*ans[n-1]*ans[n-2]
        if c1==ans[1] and c2==ans[0]:
            flag=1
            for i in range(n):
                if ans[i]==1:
                    S[i]="S"
                else:
                    S[i]="W"
            print(''.join(S))

if flag<0:

    ans[0]=-1
    ans[1]=-1

    for i in range(2,n):
        ans[i]=a[i-1]*ans[i-1]*ans[i-2]
    else:
        c1=a[0]*ans[0]*ans[n-1]
        c2=a[n-1]*ans[n-1]*ans[n-2]
        if c1==ans[1] and c2==ans[0]:
            flag=1
            for i in range(n):
                if ans[i]==1:
                    S[i]="S"
                else:
                    S[i]="W"
            print(''.join(S))

if flag<0:
    print(flag)